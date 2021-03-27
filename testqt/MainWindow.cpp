#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "qtpainterdevicecontext.h"

#include <QFontDatabase>

#include "toolkit.h"

namespace {
vrv::Toolkit *tk;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tk = new vrv::Toolkit;
//    tk->SetOption("pageWidth", std::to_string(window()->width()));
//    tk->SetOption("pageHeight", std::to_string(window()->height()));
    tk->LoadFile("/tmp/tmp.mei");
    QFontDatabase::addApplicationFont("/mnt/Local/Projects/verovio/verovio/fonts/Bravura.otf");
    QFontDatabase::addApplicationFont("/mnt/Local/Projects/verovio/verovio/fonts/Leipzig.otf");
    QFontDatabase::addApplicationFont("/mnt/Local/Projects/verovio/verovio/fonts/VerovioText-1.0.otf");

    tk->RenderToSVGFile("/tmp/tmp.svg");
}

MainWindow::~MainWindow()
{
    delete tk;
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    vrv::QtPainterDeviceContext qpdc(&painter);
    tk->RenderToDeviceContext(1, &qpdc);
}
