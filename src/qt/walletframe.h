// Copyright (c) 2011-2021 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_WALLETFRAME_H
#define BITCOIN_QT_WALLETFRAME_H

#include <QFrame>
#include <QMap>

class ClientModel;
class PlatformStyle;
class SendCoinsRecipient;
class WalletModel;
class WalletView;

QT_BEGIN_NAMESPACE
class QStackedWidget;
QT_END_NAMESPACE

/**
 * A container for embedding all wallet-related
 * controls into BitcoinGUI. The purpose of this class is to allow future
 * refinements of the wallet controls with minimal need for further
 * modifications to BitcoinGUI, thus greatly simplifying merges while
 * reducing the risk of breaking top-level stuff.
 */
class WalletFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WalletFrame(const PlatformStyle* platformStyle, QWidget* parent);
    ~WalletFrame();

    void setClientModel(ClientModel *clientModel);

    bool addView(WalletView* walletView);
    void setCurrentWallet(WalletModel* wallet_model);
    void removeWallet(WalletModel* wallet_model);
    void removeAllWallets();

    bool handlePaymentRequest(const SendCoinsRecipient& recipient);

    void showOutOfSyncWarning(bool fShow);

    QSize sizeHint() const override { return m_size_hint; }

Q_SIGNALS:
    void createWalletButtonClicked();
    void message(const QString& title, const QString& message, unsigned int style);
    void currentWalletSet();

private:
    QStackedWidget *walletStack;
    ClientModel *clientModel;
    QMap<WalletModel*, WalletView*> mapWalletViews;

    bool bOutOfSync;

    const PlatformStyle *platformStyle;

    const QSize m_size_hint;

public:
    WalletView* currentWalletView() const;
    WalletModel* currentWalletModel() const;

public Q_SLOTS:
    /** Switch to overview (home) page */
    void gotoOverviewPage();
    /** Switch to history (transactions) page */
    void gotoHistoryPage();
    /** Switch to receive coins page */
    void gotoReceiveCoinsPage();
    /** Switch to send coins page */
    void gotoSendCoinsPage(QString addr = "");

    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");

    /** Load Partially Signed Bitcoin Transaction */
    void gotoLoadPSBT(bool from_clipboard = false);

    /** Encrypt the wallet */
    void encryptWallet();
    /** Backup the wallet */
    void backupWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();

    /** Show used sending addresses */
    void usedSendingAddresses();
    /** Show used receiving addresses */
    void usedReceivingAddresses();
};
#endif // BITCOIN_QT_WALLETFRAME_H
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