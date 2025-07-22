// Returns a random DNA base
const returnRandBase = () => {
  const dnaBases = ['A', 'T', 'C', 'G'];
  return dnaBases[Math.floor(Math.random() * 4)];
};

// Returns a random single stand of DNA containing 15 bases
const mockUpStrand = () => {
  const newStrand = [];
  for (let i = 0; i < 15; i++) {
    newStrand.push(returnRandBase());
  }
  return newStrand;
};

//factory function to create a new organism
const pAequorFactory = (_specimenNum, _dna) => {
  return {
    _specimenNum,
    _dna,
    //returns the DNA of the organism
    get DNA() {
      return this._dna;
    },
    //mutates a random base in the DNA strand
    mutate() {
      const randIndex = Math.floor(Math.random() * this._dna.length);
      const randBase = returnRandBase();
      this._dna[randIndex] = randBase;
      return this._dna;
    },
    //compares the DNA of two organisms and returns the percentage of similarity
    compareDNA(otherOrganism) {
      let count = 0;
      for (let i = 0; i < this._dna.length; i++) {
        if (this._dna[i] === otherOrganism._dna[i]) {
          count++;
        }
      }
      const percentage = (count / this._dna.length) * 100;
      console.log(`Specimen #${this._specimenNum} and Specimen #${otherOrganism._specimenNum} have ${percentage.toFixed(2)}% DNA in common.`);
    },
    //returns true if the organism is likely to survive based on its DNA composition
    willLikelySurvive() {
      const survivalBases = ['C', 'G'];
      const survivalCount = this._dna.filter(base => survivalBases.includes(base)).length;
      return (survivalCount / this._dna.length) >= 0.6;
    }
  };
}

let specimenCount = 0;
let specimens = [];
while (specimenCount <= 30) {
  const newSpecimen = pAequorFactory(specimenCount, mockUpStrand());
  if (newSpecimen.willLikelySurvive()) {
    console.log(`Specimen #${newSpecimen._specimenNum} is likely to survive with DNA: ${newSpecimen._dna}`);
    specimens.push(newSpecimen);
    specimenCount++;
  } else {
    console.log(`Specimen #${newSpecimen._specimenNum} is unlikely to survive with DNA: ${newSpecimen._dna}`);
  }
}
//test cases
specimens[0].mutate();
specimens[0].compareDNA(specimens[1]);
console.log(`Specimen #${specimens[0]._specimenNum} DNA after mutation  is: ${specimens[0]._dna}`);








