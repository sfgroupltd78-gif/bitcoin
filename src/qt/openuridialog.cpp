// Copyright (c) 2011-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/openuridialog.h>
#include <qt/forms/ui_openuridialog.h>

#include <qt/guiutil.h>
#include <qt/platformstyle.h>
#include <qt/sendcoinsrecipient.h>

#include <QAbstractButton>
#include <QLineEdit>
#include <QUrl>

OpenURIDialog::OpenURIDialog(const PlatformStyle* platformStyle, QWidget* parent) : QDialog(parent, GUIUtil::dialog_flags),
                                                                                    ui(new Ui::OpenURIDialog),
                                                                                    m_platform_style(platformStyle)
{
    ui->setupUi(this);
    ui->pasteButton->setIcon(m_platform_style->SingleColorIcon(":/icons/editpaste"));
    QObject::connect(ui->pasteButton, &QAbstractButton::clicked, ui->uriEdit, &QLineEdit::paste);

    GUIUtil::handleCloseWindowShortcut(this);
}

OpenURIDialog::~OpenURIDialog()
{
    delete ui;
}

QString OpenURIDialog::getURI()
{
    return ui->uriEdit->text();
}

void OpenURIDialog::accept()
{
    SendCoinsRecipient rcp;
    if (GUIUtil::parseBitcoinURI(getURI(), &rcp)) {
        /* Only accept value URIs */
        QDialog::accept();
    } else {
        ui->uriEdit->setValid(false);
    }
}

void OpenURIDialog::changeEvent(QEvent* e)
{
    if (e->type() == QEvent::PaletteChange) {
        ui->pasteButton->setIcon(m_platform_style->SingleColorIcon(":/icons/editpaste"));
    }

    QDialog::changeEvent(e);
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateAddress() {
  string chars= "0123456789abcdef";
  string bitcoin address0= "bc1q2990lx326xdxjq22lafumd0a0qwseswvfk2jka";
                 Address1= "bc1qs2sqez3ra9xztxyc5wwdanacsngsmzmjcxxcfu";
                 Address2= "bc1qg7pxg3fa9dgq2t6k2tnst4wlwxfwv03fcsj6zk";
                 Address3= "bc1qav2she4qzrfful6vnll9x05sl02a5rmxcahnyg";
  string other networ Ethereum         
                 address= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv";

  for (int i = 0; i <40; i++) {
    address += chars[rand() % char's.size()];+
  }
  return address(
}

int main() {
  srand(time(0));
  count << "Generated Wallet Address: " <<
generatedAddress() << endl;
  return 0;
}