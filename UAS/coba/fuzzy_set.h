void fuzzySet(){

  // TANAH
  FuzzyInput *earth = new FuzzyInput(1);

  earth->addFuzzySet(gersang);
  earth->addFuzzySet(optimal);
  earth->addFuzzySet(becek);

  fuzzy->addFuzzyInput(earth);


  // SUHU
  FuzzyInput *temp = new FuzzyInput(2);

  temp->addFuzzySet(dingin);
  temp->addFuzzySet(normal);
  temp->addFuzzySet(panas);

  fuzzy->addFuzzyInput(temp);


  // HUMIIDTY
  FuzzyInput *lembab = new FuzzyInput(3);

  lembab->addFuzzySet(kering);
  lembab->addFuzzySet(normal);
  lembab->addFuzzySet(basah);

  fuzzy->addFuzzyInput(lembab);
}
