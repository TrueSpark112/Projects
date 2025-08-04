class School{
  constructor(name,level,numberOfStudents){
    this._name=name;
    this._level=level;
    this._numberOfStudents=numberOfStudents;
  }
  get name(){
    return this._name;
  }
  get level(){
    return this._level;
  }
  get numberOfStudents(){
    return this._numberOfStudents;
  }
  set numberOfStudents(num){
    if(typeof(num)==='number'){
      this._numberOfStudents=num;
      return;
    }
    console.log('Invalid input: numberOfStudents must be set to a Number.');
  }
  quickFacts(){
    console.log(`${this.name} educates ${this.numberOfStudents} students at the ${this.level} school level.
`)
  }
  static pickSubstituteTeacher(substituteTeachers){
    return substituteTeachers[Math.floor(Math.random()*substituteTeachers.length)];
  }
}
class Primary extends School{
  constructor(name,numberOfStudents,pickupPolicy){
    super(name,'primary',numberOfStudents,);
    this._pickupPolicy=pickupPolicy;
  }
  get pickUpPolicy(){
    return this._pickupPolicy;
  }
}
class Middle extends School{
  constructor(name,numberOfStudents){
    super(name,'middle',numberOfStudents);
  }
}
class High extends School{
  constructor(name,numberOfStudents,sportsTeams){
    super(name,'high',numberOfStudents);
    this._sportsTeams=sportsTeams;
  }
}
const stonyHurst= new Middle('StonyHurst',1000);
stonyHurst.quickFacts();
console.log(Middle.pickSubstituteTeacher(['Lord Farquaad','Shrek','Gojo','Naruto']));