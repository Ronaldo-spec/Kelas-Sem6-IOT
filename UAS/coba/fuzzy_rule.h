void fuzzyRule(){

//-------------------------------- FUZZY RULE 111 ------------------------------
  FuzzyRuleAntecedent *dingin_kering_1 = new FuzzyRuleAntecedent();
  dingin_kering_1->joinWithAND(dingin,kering);

  FuzzyRuleAntecedent *a_gersang = new FuzzyRuleAntecedent();
  a_gersang->joinSingle(gersang);

  FuzzyRuleAntecedent *dingin_kering_gersang_1 = new FuzzyRuleAntecedent();
  dingin_kering_gersang_1->joinWithAND(dingin_kering_1, a_gersang);

  FuzzyRuleConsequent *q_a_1 = new FuzzyRuleConsequent();
  q_a_1->addOutput(q);
  q_a_1->addOutput(a);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, dingin_kering_gersang_1, q_a_1);
  fuzzy->addFuzzyRule(fuzzyRule1);
  

//-------------------------------- FUZZY RULE 112 ------------------------------
  FuzzyRuleAntecedent *dingin_kering_2 = new FuzzyRuleAntecedent();
  dingin_kering_2->joinWithAND(dingin,kering);

  FuzzyRuleAntecedent *s_optimal = new FuzzyRuleAntecedent();
  s_optimal->joinSingle(optimal);

  FuzzyRuleAntecedent *dingin_kering_optimal_2 = new FuzzyRuleAntecedent();
  dingin_kering_optimal_2->joinWithAND(dingin_kering_2, s_optimal);
  FuzzyRuleConsequent *q_s_2 = new FuzzyRuleConsequent();
  q_s_2->addOutput(q);
  q_s_2->addOutpu(s);

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, dingin_kering_optimal_2, q_s_2);
  fuzzy->addFuzzyRule(fuzzyRule2);
  
  //-------------------------------- FUZZY RULE 113 ------------------------------
  FuzzyRuleAntecedent *dingin_kering_3 = new FuzzyRuleAntecedent();
  dingin_kering_3->joinWithAND(dingin,kering);

  FuzzyRuleAntecedent *d_becek = new FuzzyRuleAntecedent();
  d_becek->joinSingle(becek);

  FuzzyRuleAntecedent *dingin_kering_becek_3 = new FuzzyRuleAntecedent();
  dingin_kering_becek_3->joinWithAND(dingin_kering_3, d_becek);
  FuzzyRuleConsequent *q_d_3 = new FuzzyRuleConsequent();
  q_d_3->addOutput(q);
  q_d_3->addOutpu(d);

  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, dingin_kering_becek_3, q_d_3);
  fuzzy->addFuzzyRule(fuzzyRule3);

  //-------------------------------- FUZZY RULE 211 ------------------------------
  FuzzyRuleAntecedent *hangat_kering_1 = new FuzzyRuleAntecedent();
  hangat_kering_1->joinWithAND(hangat,kering);

  FuzzyRuleAntecedent *a_gersang = new FuzzyRuleAntecedent();
  a_gersang->joinSingle(gersang);

  FuzzyRuleAntecedent *hangat_kering_gersang_1 = new FuzzyRuleAntecedent();
  hangat_kering_gersang_1->joinWithAND(hangat_kering_1, a_gersang);

  FuzzyRuleConsequent *q_a_1 = new FuzzyRuleConsequent();
  w_a_1->addOutput(w);
  w_a_1->addOutput(a);

  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, hangat_kering_gersang_1, w_a_1);
  fuzzy->addFuzzyRule(fuzzyRule4);

  //-------------------------------- FUZZY RULE 212 ------------------------------
  FuzzyRuleAntecedent *hangat_kering_2 = new FuzzyRuleAntecedent();
  hangat_kering_2->joinWithAND(hangat,kering);

  FuzzyRuleAntecedent *s_optimal = new FuzzyRuleAntecedent();
  s_optimal->joinSingle(optimal);

  FuzzyRuleAntecedent *hangat_kering_optimal_2 = new FuzzyRuleAntecedent();
  hangat_kering_optimal_2->joinWithAND(hangat_kering_2, s_optimal);
  FuzzyRuleConsequent *w_s_2 = new FuzzyRuleConsequent();
  w_s_2->addOutput(w);
  w_s_2->addOutpu(s);

  FuzzyRule *fuzzyRule5 = new FuzzyRule(5, hangat_kering_optimal_2, w_s_2);
  fuzzy->addFuzzyRule(fuzzyRule5);

  //-------------------------------- FUZZY RULE 213 ------------------------------
  FuzzyRuleAntecedent *hangat_kering_3 = new FuzzyRuleAntecedent();
  hangat_kering_3->joinWithAND(hangat,kering);

  FuzzyRuleAntecedent *d_becek = new FuzzyRuleAntecedent();
  d_becek->joinSingle(becek);

  FuzzyRuleAntecedent *hangat_kering_becek_3 = new FuzzyRuleAntecedent();
  hangat_kering_becek_3->joinWithAND(hangat_kering_3, d_becek);
  FuzzyRuleConsequent *w_d_3 = new FuzzyRuleConsequent();
  w_d_3->addOutput(w);
  w _d_3->addOutpu(d);

  FuzzyRule *fuzzyRule6 = new FuzzyRule(6, hangat_kering_becek_3, w_d_3);
  fuzzy->addFuzzyRule(fuzzyRule6);
}
