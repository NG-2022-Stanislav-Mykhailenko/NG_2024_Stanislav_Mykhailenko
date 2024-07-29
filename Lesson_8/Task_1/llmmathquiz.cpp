#include "llmmathquiz.h"
#include "ui_llmmathquiz.h"

LlmMathQuiz::LlmMathQuiz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LlmMathQuiz)
{
    ui->setupUi(this);
    connect(ui->b_submit, &QPushButton::clicked, this, &LlmMathQuiz::submit);
    connect(ui->b_generate, &QPushButton::clicked, this, &LlmMathQuiz::generate);
    connect (m_manager, &QNetworkAccessManager::finished, this, &LlmMathQuiz::newAnswer);
}

LlmMathQuiz::~LlmMathQuiz()
{
    delete ui;
}

void LlmMathQuiz::submit()
{
    if (ui->e_user->text().isEmpty())
        return;

    ui->e_llm->setText(m_llmAnswer);
    ui->b_submit->setEnabled(false);
    ui->e_user->setReadOnly(true);
    ui->l_opinion->setText("Generating…");

    sendPrompt("The two following lines will contain two answers. Respond with \"true\" if they are the same, and \"false\" if they are not. Always use lowercase."
               + QString("\n") + ui->e_user->text()
               + QString("\n") + m_llmAnswer);
}

void LlmMathQuiz::generate()
{
    if (m_taskReceived) {
        ui->l_number->setText(QString::number(ui->l_number->text().toInt() + 1));
        m_taskReceived = false;
    }
    m_taskReceived = false;
    ui->b_generate->setEnabled(false);
    ui->e_task->setText("Generating…");
    ui->e_user->clear();
    ui->e_llm->clear();
    ui->l_opinion->setText("Not checked");

    sendPrompt("Generate a mathematical task and a correct answer for it. Both the task and the answer need to take only one line. Provide the task on the first line, and the answer on the second line.");
}

void LlmMathQuiz::newAnswer(QNetworkReply *reply)
{
    if (!m_taskReceived) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray textReply = reply->readAll();
            QStringList data = QJsonDocument::fromJson(textReply).object().value("response").toString().split('\n');
            ui->e_task->setText(data[0]);
            m_llmAnswer = data[1].isEmpty() ? data[2] : data[1];
            m_taskReceived = true;
            ui->b_submit->setEnabled(true);
            ui->e_user->setReadOnly(false);
        } else {
            ui->e_task->setText("Error!");
            ui->b_generate->setEnabled(true);
        }
    } else {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray textReply = reply->readAll();
            QString data = QJsonDocument::fromJson(textReply).object().value("response").toString();
            if (data == "true") {
                ui->l_matched->setText(QString::number(ui->l_matched->text().toInt() + 1));
                ui->l_opinion->setText("Match");
            } else if (data == "false")
                ui->l_opinion->setText("Mismatch");
            else
                ui->l_opinion->setText("Not match nor mismatch");
            ui->b_generate->setEnabled(true);
        } else {
            ui->e_llm->setText("Error!");
            ui->b_submit->setEnabled(true);
        }
    }
}

void LlmMathQuiz::sendPrompt(QString prompt)
{
    QNetworkRequest request(QUrl("http://127.0.0.1:11434/api/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["model"] = "llama3.1:8b";
    json["prompt"] = prompt;
    json["stream"] = false;

    m_manager->post(request, QJsonDocument(json).toJson());
}
