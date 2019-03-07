#include "xrhall.h"
#include "ui_xrhall.h"
#include "engine/uiinc.h"
#include "engine/macro.h"

xrHall::xrHall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xrHall)
{
    ui->setupUi(this);

    initialize();

    this->setWindowTitle("Welcome to PentaZen!");

    vtext = "AI v1.1.4, UI v1.0.0";
    ui->versionLabel->setText(vtext);
    ui->versionLabel->setAlignment(Qt::AlignCenter);

    chesscolor = new QButtonGroup(this);
    chesscolor->addButton(ui->black,1);
    chesscolor->addButton(ui->white,2);
    ui->black->setChecked(true);

    edition = new QButtonGroup(this);

    /* Edited by Sun */
//  edition->addButton(ui->proEdition,1);
//  edition->addButton(ui->pubEdition,0);
//  ui->proEdition->setChecked(true);
//  set_forbidden(edition->checkedId());
    set_forbidden(true);
}

xrHall::~xrHall()
{
    uninitialize();
    delete ui;
}

void xrHall::game()
{
    depth = ui->modelBox->currentIndex();
    set_difficulty(depth);
    room = new xrRoom(vtext, depth, chesscolor->checkedId());
    room->show();
}

void xrHall::on_startButton_clicked()
{
    game();
}
