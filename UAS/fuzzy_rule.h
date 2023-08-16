void rule(){
FuzzyInput *kdrAir = new FuzzyInput(3);
  kdrAir->addFuzzySet(rendah);
  kdrAir->addFuzzySet(medium);
  kdrAir->addFuzzySet(tinggi);
  fuzzy->addFuzzyInput(kdrAir);

FuzzyOutput *stateKadar = new FuzzyOutput(2);
  stateKadar->addFuzzySet(kadarGiling);
  stateKadar->addFuzzySet(kadarSimpan);
  stateKadar->addFuzzySet(kadarPanen);
  fuzzy->addFuzzyOutput(stateKadar);
  
  FuzzyRuleConsequent *thenKadarTinggi = new FuzzyRuleConsequent();
    thenKadarTinggi->addOutput(kadarPanen);
  FuzzyRuleConsequent *thenKadarMedium = new FuzzyRuleConsequent();
    thenKadarMedium->addOutput(kadarSimpan);
  FuzzyRuleConsequent *thenKadarRendah = new FuzzyRuleConsequent();
    thenKadarRendah->addOutput(kadarGiling);
//-------------------
  FuzzyRuleAntecedent *ifKadarAirTinggi = new FuzzyRuleAntecedent();
    ifKadarAirTinggi->joinSingle(tinggi);
  FuzzyRuleAntecedent *ifKadarAirMedium = new FuzzyRuleAntecedent();
    ifKadarAirMedium->joinSingle(medium);    
  FuzzyRuleAntecedent *ifKadarAirRendah = new FuzzyRuleAntecedent();
    ifKadarAirRendah->joinSingle(rendah);

      
  FuzzyRule *rule1 = new FuzzyRule(1, ifKadarAirTinggi, thenKadarTinggi);
    fuzzy->addFuzzyRule(rule1);
  FuzzyRule *rule2 = new FuzzyRule(2, ifKadarAirMedium, thenKadarMedium);
    fuzzy->addFuzzyRule(rule2);
  FuzzyRule *rule3 = new FuzzyRule(3, ifKadarAirRendah, thenKadarRendah);
    fuzzy->addFuzzyRule(rule3);
    
}
