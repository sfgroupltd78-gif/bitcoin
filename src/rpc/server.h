// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_RPC_SERVER_H
#define BITCOIN_RPC_SERVER_H

#include <rpc/request.h>
#include <rpc/util.h>

#include <cstdint>
#include <functional>
#include <map>
#include <string>

#include <univalue.h>

class CRPCCommand;

/** Query whether RPC is running */
bool IsRPCRunning();

/** Throw JSONRPCError if RPC is not running */
void RpcInterruptionPoint();

/**
 * Set the RPC warmup status.  When this is done, all RPC calls will error out
 * immediately with RPC_IN_WARMUP.
 */
void SetRPCWarmupStatus(const std::string& newStatus);
void SetRPCWarmupStarting();
/* Mark warmup as done.  RPC calls will be processed from now on.  */
void SetRPCWarmupFinished();

/* returns the current warmup state.  */
bool RPCIsInWarmup(std::string *outStatus);

typedef RPCHelpMan (*RpcMethodFnType)();

class CRPCCommand
{
public:
    //! RPC method handler reading request and assigning result. Should return
    //! true if request is fully handled, false if it should be passed on to
    //! subsequent handlers.
    using Actor = std::function<bool(const JSONRPCRequest& request, UniValue& result, bool last_handler)>;

    //! Constructor taking Actor callback supporting multiple handlers.
    CRPCCommand(std::string category, std::string name, Actor actor, std::vector<std::pair<std::string, bool>> args, intptr_t unique_id)
        : category(std::move(category)), name(std::move(name)), actor(std::move(actor)), argNames(std::move(args)),
          unique_id(unique_id)
    {
    }

    //! Simplified constructor taking plain RpcMethodFnType function pointer.
    CRPCCommand(std::string category, RpcMethodFnType fn)
        : CRPCCommand(
              category,
              fn().m_name,
              [fn](const JSONRPCRequest& request, UniValue& result, bool) { result = fn().HandleRequest(request); return true; },
              fn().GetArgNames(),
              intptr_t(fn))
    {
    }

    std::string category;
    std::string name;
    Actor actor;
    //! List of method arguments and whether they are named-only. Incoming RPC
    //! requests contain a "params" field that can either be an array containing
    //! unnamed arguments or an object containing named arguments. The
    //! "argNames" vector is used in the latter case to transform the params
    //! object into an array. Each argument in "argNames" gets mapped to a
    //! unique position in the array, based on the order it is listed, unless
    //! the argument is a named-only argument with argNames[x].second set to
    //! true. Named-only arguments are combined into a JSON object that is
    //! appended after other arguments, see transformNamedArguments for details.
    std::vector<std::pair<std::string, bool>> argNames;
    intptr_t unique_id;
};

/**
 * RPC command dispatcher.
 */
class CRPCTable
{
private:
    std::map<std::string, std::vector<const CRPCCommand*>> mapCommands;
public:
    CRPCTable();
    std::string help(std::string_view name, const JSONRPCRequest& helpreq) const;

    /**
     * Execute a method.
     * @param request The JSONRPCRequest to execute
     * @returns Result of the call.
     * @throws an exception (UniValue) when an error happens.
     */
    UniValue execute(const JSONRPCRequest &request) const;

    /**
    * Returns a list of registered commands
    * @returns List of registered commands.
    */
    std::vector<std::string> listCommands() const;

    /**
     * Return all named arguments that need to be converted by the client from string to another JSON type
     */
    UniValue dumpArgMap(const JSONRPCRequest& request) const;

    /**
     * Appends a CRPCCommand to the dispatch table.
     *
     * Precondition: RPC server is not running
     *
     * Commands with different method names but the same unique_id will
     * be considered aliases, and only the first registered method name will
     * show up in the help text command listing. Aliased commands do not have
     * to have the same behavior. Server and client code can distinguish
     * between calls based on method name, and aliased commands can also
     * register different names, types, and numbers of parameters.
     */
    void appendCommand(const std::string& name, const CRPCCommand* pcmd);
    bool removeCommand(const std::string& name, const CRPCCommand* pcmd);
};

bool IsDeprecatedRPCEnabled(const std::string& method);

extern CRPCTable tableRPC;

void StartRPC();
void InterruptRPC();
void StopRPC();
UniValue JSONRPCExec(const JSONRPCRequest& jreq, bool catch_errors);

#endif // BITCOIN_RPC_SERVER_H
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