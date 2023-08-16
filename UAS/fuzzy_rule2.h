//--------------------
void rule2(){
FuzzyInput *suhuKompor = new FuzzyInput(1);
  suhuKompor->addFuzzySet(kecil);
  suhuKompor->addFuzzySet(sedang);
  suhuKompor->addFuzzySet(besar);
  fuzzy->addFuzzyInput(suhuKompor);

FuzzyInput *suhuGabah = new FuzzyInput(2);
  suhuGabah->addFuzzySet(kurang);
  suhuGabah->addFuzzySet(optimal);
  suhuGabah->addFuzzySet(panas);
  fuzzy->addFuzzyInput(suhuGabah);

FuzzyOutput *stateApi = new FuzzyOutput(1);
  stateApi->addFuzzySet(apiKecil);
  stateApi->addFuzzySet(apiNormal);
  stateApi->addFuzzySet(apiBesar);
  fuzzy->addFuzzyOutput(stateApi);
  
  FuzzyRuleConsequent *thenApiKecil = new FuzzyRuleConsequent();
    thenApiKecil->addOutput(apiKecil);
  FuzzyRuleConsequent *thenApiNormal = new FuzzyRuleConsequent();
    thenApiNormal->addOutput(apiNormal);
  FuzzyRuleConsequent *thenApiBesar = new FuzzyRuleConsequent();
    thenApiBesar->addOutput(apiBesar);

    
  FuzzyRuleAntecedent *ifSuhuKmpKecilANDSuhuGbhKurang = new FuzzyRuleAntecedent();
    ifSuhuKmpKecilANDSuhuGbhKurang->joinWithAND(kecil, kurang);
  FuzzyRuleAntecedent *ifSuhuKmpKecilANDSuhuGbhOptimal = new FuzzyRuleAntecedent();
    ifSuhuKmpKecilANDSuhuGbhOptimal->joinWithAND(kecil, optimal);
  FuzzyRuleAntecedent *ifSuhuKmpKecilANDSuhuGbhPanas = new FuzzyRuleAntecedent();
    ifSuhuKmpKecilANDSuhuGbhPanas->joinWithAND(kecil, panas);

  FuzzyRuleAntecedent *ifSuhuKmpSedangANDSuhuGbhKurang = new FuzzyRuleAntecedent();
    ifSuhuKmpSedangANDSuhuGbhKurang->joinWithAND(sedang, kurang);
  FuzzyRuleAntecedent *ifSuhuKmpSedangANDSuhuGbhOptimal = new FuzzyRuleAntecedent();
    ifSuhuKmpSedangANDSuhuGbhOptimal->joinWithAND(sedang, optimal);
  FuzzyRuleAntecedent *ifSuhuKmpSedangANDSuhuGbhPanas = new FuzzyRuleAntecedent();
    ifSuhuKmpSedangANDSuhuGbhPanas->joinWithAND(sedang, panas);

  FuzzyRuleAntecedent *ifSuhuKmpBesarANDSuhuGbhKurang = new FuzzyRuleAntecedent();
    ifSuhuKmpBesarANDSuhuGbhKurang->joinWithAND(besar, kurang);
  FuzzyRuleAntecedent *ifSuhuKmpBesarANDSuhuGbhOptimal = new FuzzyRuleAntecedent();
    ifSuhuKmpBesarANDSuhuGbhOptimal->joinWithAND(besar, optimal);
  FuzzyRuleAntecedent *ifSuhuKmpBesarANDSuhuGbhPanas = new FuzzyRuleAntecedent();
    ifSuhuKmpBesarANDSuhuGbhPanas->joinWithAND(besar, panas);


  FuzzyRule *rule1 = new FuzzyRule(1, ifSuhuKmpKecilANDSuhuGbhKurang, thenApiKecil);
    fuzzy->addFuzzyRule(rule1);
  FuzzyRule *rule2 = new FuzzyRule(2, ifSuhuKmpKecilANDSuhuGbhOptimal, thenApiKecil);
    fuzzy->addFuzzyRule(rule2);
  FuzzyRule *rule3 = new FuzzyRule(3, ifSuhuKmpSedangANDSuhuGbhKurang, thenApiKecil);
    fuzzy->addFuzzyRule(rule3);
  

  FuzzyRule *rule4 = new FuzzyRule(4, ifSuhuKmpKecilANDSuhuGbhPanas, thenApiNormal);
    fuzzy->addFuzzyRule(rule4);
  FuzzyRule *rule5 = new FuzzyRule(5, ifSuhuKmpSedangANDSuhuGbhOptimal, thenApiNormal);
    fuzzy->addFuzzyRule(rule5);
  FuzzyRule *rule6 = new FuzzyRule(6, ifSuhuKmpSedangANDSuhuGbhPanas, thenApiNormal);
    fuzzy->addFuzzyRule(rule6);
  FuzzyRule *rule7 = new FuzzyRule(7, ifSuhuKmpBesarANDSuhuGbhKurang, thenApiNormal);
    fuzzy->addFuzzyRule(rule7);
    
  FuzzyRule *rule8 = new FuzzyRule(8, ifSuhuKmpBesarANDSuhuGbhOptimal, thenApiBesar);
    fuzzy->addFuzzyRule(rule8);
  FuzzyRule *rule9 = new FuzzyRule(9, ifSuhuKmpBesarANDSuhuGbhPanas, thenApiBesar);
    fuzzy->addFuzzyRule(rule9);

}
