set(ts_files
  bitcoin_am.ts
  bitcoin_ar.ts
  bitcoin_ast_ES.ts
  bitcoin_az.ts
  bitcoin_az@latin.ts
  bitcoin_be.ts
  bitcoin_bg.ts
  bitcoin_bn.ts
  bitcoin_br.ts
  bitcoin_bs.ts
  bitcoin_ca.ts
  bitcoin_cmn.ts
  bitcoin_cs.ts
  bitcoin_cy.ts
  bitcoin_da.ts
  bitcoin_de.ts
  bitcoin_el.ts
  bitcoin_en.ts
  bitcoin_eo.ts
  bitcoin_es.ts
  bitcoin_et.ts
  bitcoin_eu.ts
  bitcoin_fa.ts
  bitcoin_fi.ts
  bitcoin_fil.ts
  bitcoin_fo.ts
  bitcoin_fr.ts
  bitcoin_ga.ts
  bitcoin_ga_IE.ts
  bitcoin_gl.ts
  bitcoin_gl_ES.ts
  bitcoin_gu.ts
  bitcoin_hak.ts
  bitcoin_he.ts
  bitcoin_hi.ts
  bitcoin_hr.ts
  bitcoin_hu.ts
  bitcoin_id.ts
  bitcoin_is.ts
  bitcoin_it.ts
  bitcoin_ja.ts
  bitcoin_ka.ts
  bitcoin_kk.ts
  bitcoin_kk@latin.ts
  bitcoin_km.ts
  bitcoin_kn.ts
  bitcoin_ko.ts
  bitcoin_ku.ts
  bitcoin_ku_IQ.ts
  bitcoin_lt.ts
  bitcoin_lv.ts
  bitcoin_mi.ts
  bitcoin_mk.ts
  bitcoin_ml.ts
  bitcoin_mn.ts
  bitcoin_ms.ts
  bitcoin_mt.ts
  bitcoin_nb.ts
  bitcoin_ne.ts
  bitcoin_nl.ts
  bitcoin_no.ts
  bitcoin_pam.ts
  bitcoin_pl.ts
  bitcoin_ps.ts
  bitcoin_pt.ts
  bitcoin_pt_BR.ts
  bitcoin_ro.ts
  bitcoin_ru.ts
  bitcoin_si.ts
  bitcoin_sk.ts
  bitcoin_sl.ts
  bitcoin_sm.ts
  bitcoin_sq.ts
  bitcoin_sr.ts
  bitcoin_sr@ijekavianlatin.ts
  bitcoin_sr@latin.ts
  bitcoin_sv.ts
  bitcoin_sw.ts
  bitcoin_szl.ts
  bitcoin_ta.ts
  bitcoin_te.ts
  bitcoin_th.ts
  bitcoin_tk.ts
  bitcoin_tl.ts
  bitcoin_tr.ts
  bitcoin_uk.ts
  bitcoin_ur.ts
  bitcoin_uz.ts
  bitcoin_uz@Cyrl.ts
  bitcoin_uz@Latn.ts
  bitcoin_ve.ts
  bitcoin_yi.ts
  bitcoin_yue.ts
  bitcoin_zh-Hans.ts
  bitcoin_zh-Hant.ts
  bitcoin_zh_CN.ts
  bitcoin_zh_HK.ts
  bitcoin_zh_TW.ts
)
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