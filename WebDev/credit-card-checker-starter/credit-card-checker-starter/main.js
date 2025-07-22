// All valid credit card numbers
const valid1 = [4, 5, 3, 9, 6, 7, 7, 9, 0, 8, 0, 1, 6, 8, 0, 8]
const valid2 = [5, 5, 3, 5, 7, 6, 6, 7, 6, 8, 7, 5, 1, 4, 3, 9]
const valid3 = [3, 7, 1, 6, 1, 2, 0, 1, 9, 9, 8, 5, 2, 3, 6]
const valid4 = [6, 0, 1, 1, 1, 4, 4, 3, 4, 0, 6, 8, 2, 9, 0, 5]
const valid5 = [4, 5, 3, 9, 4, 0, 4, 9, 6, 7, 8, 6, 9, 6, 6, 6]

// All invalid credit card numbers
const invalid1 = [4, 5, 3, 2, 7, 7, 8, 7, 7, 1, 0, 9, 1, 7, 9, 5]
const invalid2 = [5, 7, 9, 5, 5, 9, 3, 3, 9, 2, 1, 3, 4, 6, 4, 3]
const invalid3 = [3, 7, 5, 7, 9, 6, 0, 8, 4, 4, 5, 9, 9, 1, 4]
const invalid4 = [6, 0, 1, 1, 1, 2, 7, 9, 6, 1, 7, 7, 7, 9, 3, 5]
const invalid5 = [5, 3, 8, 2, 0, 1, 9, 7, 7, 2, 8, 8, 3, 8, 5, 4]

// Can be either valid or invalid
const mystery1 = [3, 4, 4, 8, 0, 1, 9, 6, 8, 3, 0, 5, 4, 1, 4]
const mystery2 = [5, 4, 6, 6, 1, 0, 0, 8, 6, 1, 6, 2, 0, 2, 3, 9]
const mystery3 = [6, 0, 1, 1, 3, 7, 7, 0, 2, 0, 9, 6, 2, 6, 5, 6, 2, 0, 3]
const mystery4 = [4, 9, 2, 9, 8, 7, 7, 1, 6, 9, 2, 1, 7, 0, 9, 3]
const mystery5 = [4, 9, 1, 3, 5, 4, 0, 4, 6, 3, 0, 7, 2, 5, 2, 3]

// An array of all the arrays above
const batch = [valid1, valid2, valid3, valid4, valid5, invalid1, invalid2, invalid3, invalid4, invalid5, mystery1, mystery2, mystery3, mystery4, mystery5]


// Add your functions below:
//returns true when an array contains digits of a valid credit card number
//returns false when an array contains digits of an invalid credit card number
//this function should not modify the original array
const validateCred= (arr) => {
    //starting from the farthest digit to the right, iterate to the left
    let sum = 0;
    for (let i = arr.length - 1; i >= 0; i--){
        //every other diigit is multiplied by 2
        if ((arr.length - 1 - i) % 2 === 1) {
            let doubleDigit = arr[i] * 2;
            //if the result is greater than 9, subtract 9 from it
            if (doubleDigit > 9) {
                doubleDigit -= 9;
            }
            sum += doubleDigit;
        }
        //if the digit is not multiplied by 2, add it to the sum
        else {
            sum += arr[i];
        }
    }
    //if the sum is divisible by 10, the credit card number is valid
    return sum % 10 === 0;
}
//checks through a nested array for which numbers are invalid and returns another nested array 
//with invalid credit card numbers
const findInvalidCards = (nestedArr) => {
    const invalidCards = [];
    for (let i = 0; i < nestedArr.length; i++) {
        if (!validateCred(nestedArr[i])) {
            invalidCards.push(nestedArr[i]);
        }
    }
    return invalidCards;
}

//Input: a nested array of invalid numbers
//Output: an array of companies that issued the invalid credit cards
const idInvalidCardCompanies = (nestedArr) => {
    const companies = [];
    for (let i = 0; i < nestedArr.length; i++) {
        const firstDigit = nestedArr[i][0];
        //check if the first digit is already in the companies array
        if (!companies.includes(firstDigit)) {
            switch (firstDigit) {
                case 3:
                    companies.push('Amex (American Express)');
                    break;
                case 4:
                    companies.push('Visa');
                    break;
                case 5:
                    companies.push('Mastercard');
                    break;
                case 6:
                    companies.push('Discover');
                    break;
                default:
                    companies.push('Company not found');
            }
        }
    }
    return companies;
}

// Test cases
console.log(validateCred(valid1)); // true
console.log(validateCred(invalid1)); // false
console.log(findInvalidCards(batch)); // returns an array of invalid credit card numbers
console.log(idInvalidCardCompanies(findInvalidCards(batch))); // returns an array of companies that issued the invalid credit cards 