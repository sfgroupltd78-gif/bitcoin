// Copyright (c) 2020-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <httpserver.h>
#include <netaddress.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>
#include <util/signalinterrupt.h>
#include <util/strencodings.h>

#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <event2/http_struct.h>

#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

extern "C" int evhttp_parse_firstline_(struct evhttp_request*, struct evbuffer*);
extern "C" int evhttp_parse_headers_(struct evhttp_request*, struct evbuffer*);

std::string RequestMethodString(HTTPRequest::RequestMethod m);

FUZZ_TARGET(http_request)
{
    FuzzedDataProvider fuzzed_data_provider{buffer.data(), buffer.size()};
    evhttp_request* evreq = evhttp_request_new(nullptr, nullptr);
    assert(evreq != nullptr);
    evreq->kind = EVHTTP_REQUEST;
    evbuffer* evbuf = evbuffer_new();
    assert(evbuf != nullptr);
    const std::vector<uint8_t> http_buffer = ConsumeRandomLengthByteVector(fuzzed_data_provider, 4096);
    evbuffer_add(evbuf, http_buffer.data(), http_buffer.size());
    // Avoid constructing requests that will be interpreted by libevent as PROXY requests to avoid triggering
    // a nullptr dereference. The dereference (req->evcon->http_server) takes place in evhttp_parse_request_line
    // and is a consequence of our hacky but necessary use of the internal function evhttp_parse_firstline_ in
    // this fuzzing harness. The workaround is not aesthetically pleasing, but it successfully avoids the troublesome
    // code path. " http:// HTTP/1.1\n" was a crashing input prior to this workaround.
    const std::string http_buffer_str = ToLower(std::string{http_buffer.begin(), http_buffer.end()});
    if (http_buffer_str.find(" http://") != std::string::npos || http_buffer_str.find(" https://") != std::string::npos ||
        evhttp_parse_firstline_(evreq, evbuf) != 1 || evhttp_parse_headers_(evreq, evbuf) != 1) {
        evbuffer_free(evbuf);
        evhttp_request_free(evreq);
        return;
    }

    util::SignalInterrupt interrupt;
    HTTPRequest http_request{evreq, interrupt, true};
    const HTTPRequest::RequestMethod request_method = http_request.GetRequestMethod();
    (void)RequestMethodString(request_method);
    (void)http_request.GetURI();
    (void)http_request.GetHeader("Host");
    const std::string header = fuzzed_data_provider.ConsumeRandomLengthString(16);
    (void)http_request.GetHeader(header);
    (void)http_request.WriteHeader(header, fuzzed_data_provider.ConsumeRandomLengthString(16));
    (void)http_request.GetHeader(header);
    const std::string body = http_request.ReadBody();
    assert(body.empty());
    const CService service = http_request.GetPeer();
    assert(service.ToStringAddrPort() == "[::]:0");

    evbuffer_free(evbuf);
    evhttp_request_free(evreq);
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
                 address4= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv";
       BNB chain address5= "0x2e907840910285F959E3664569A576C8f973DdB3";
            USDT address6: "0xaD9C8D299c9F7082cEF30F14D366787621a254F5";
   CoinEx wallet address7= "qrqghy3sltp9yrqkjtjlcjv96xrsnl7nxs7cv282yt";
          solana address8= "tUhjxdfyxzi92NNsAJn5zdWCvo26cU7AiDbT75Rg1qv":

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