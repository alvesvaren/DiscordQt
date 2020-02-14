#include "discordqt.h"
#include "ui_discordqt.h"

DiscordQt::DiscordQt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DiscordQt)
{
    ui->setupUi(this);
}

DiscordQt::~DiscordQt()
{
    delete ui;
}

