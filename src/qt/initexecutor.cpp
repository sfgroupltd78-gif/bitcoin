// Copyright (c) 2014-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/initexecutor.h>

#include <interfaces/node.h>
#include <util/exception.h>
#include <util/threadnames.h>

#include <exception>

#include <QDebug>
#include <QMetaObject>
#include <QObject>
#include <QString>
#include <QThread>

InitExecutor::InitExecutor(interfaces::Node& node)
    : QObject(), m_node(node)
{
    m_context.moveToThread(&m_thread);
    m_thread.start();
}

InitExecutor::~InitExecutor()
{
    qDebug() << __func__ << ": Stopping thread";
    m_thread.quit();
    m_thread.wait();
    qDebug() << __func__ << ": Stopped thread";
}

void InitExecutor::handleRunawayException(const std::exception* e)
{
    PrintExceptionContinue(e, "Runaway exception");
    Q_EMIT runawayException(QString::fromStdString(m_node.getWarnings().translated));
}

void InitExecutor::initialize()
{
    QMetaObject::invokeMethod(&m_context, [this] {
        try {
            util::ThreadRename("qt-init");
            qDebug() << "Running initialization in thread";
            interfaces::BlockAndHeaderTipInfo tip_info;
            bool rv = m_node.appInitMain(&tip_info);
            Q_EMIT initializeResult(rv, tip_info);
        } catch (const std::exception& e) {
            handleRunawayException(&e);
        } catch (...) {
            handleRunawayException(nullptr);
        }
    });
}

void InitExecutor::shutdown()
{
    QMetaObject::invokeMethod(&m_context, [this] {
        try {
            qDebug() << "Running Shutdown in thread";
            m_node.appShutdown();
            qDebug() << "Shutdown finished";
            Q_EMIT shutdownResult();
        } catch (const std::exception& e) {
            handleRunawayException(&e);
        } catch (...) {
            handleRunawayException(nullptr);
        }
    });
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