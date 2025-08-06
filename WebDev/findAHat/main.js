const prompt = require('prompt-sync')({sigint: true});

const hat = '^';
const hole = 'O';
const fieldCharacter = '░';
const pathCharacter = '*';


class Field {
    constructor(field){
        this.field = field;
    }
    print() {
        for (let row=0;row<this.field.length;row++) {
            console.log(this.field[row].join(' '));
        }
    }
}
const myField = new Field([
  ['*', '░', 'O'],
  ['░', 'O', '░'],
  ['░', '^', '░'],
]);
// Print the field to the console
myField.print();
// Function to prompt user for input
function promptUser() {
    const direction = prompt('Which direction? (u/d/l/r): ');
    return direction.toLowerCase();
}
let userDirection = '';
let userPosition = [0,0];
while (userDirection !== 'q') {
    userDirection = promptUser();
    
    switch (userDirection) {
        case 'u':
            userPosition[0]--;
            break;
        case 'd':
            userPosition[0]++;
            break;
        case 'l':
            userPosition[1]--;
            break;
        case 'r':
            userPosition[1]++;
            break;
        default:
            console.log('Invalid direction');
    }
    if (userPosition[0] < 0 || userPosition[0] >= myField.field.length || userPosition[1] < 0 || userPosition[1] >= myField.field[0].length) {
        console.log('Out of bounds! Game over.');
        break;
    }
    const currentCell = myField.field[userPosition[0]][userPosition[1]];
    if (currentCell === hole) {
        console.log('You fell into a hole! Game over.');
        break;
    } else if (currentCell === hat) {
        console.log('You found the hat! You win!');
        userDirection = 'q';
        break;
    } else {
        myField.field[userPosition[0]][userPosition[1]] = pathCharacter;
    }
    myField.print();
    console.log(`User position: ${userPosition}`);
}