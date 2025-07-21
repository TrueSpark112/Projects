#Question 2
"""
#BEFORE: A character in the ciphertext, the number you want to shift by,
#       the index in the string
#AFTER: Replaces the character in the cyphertext by shifting to the left
def shiftLetterL(cyphertext,shift,index):
    if(cyphertext[index] == ' '):
        return
    store = cyphertext[index]
    cyphertext[index] = chr(((ord(cyphertext[index])-97-shift)%26)+97)


#BEFORE: A character in the plaintext, the number you want to shift by,
#       the index in the string
#AFTER: A character in the ciphertext
def shiftLetterR(plainText,shift,index):
    if(plainText[index] == ' '):
        return
    temp = plainText[index]
    plainText[index] = chr(((ord(plainText[index])-97+shift)%26)+97)




#Encrypts a plaintext and Outputs the Ciphertext
#BEFORE: Two strings, one for the plaintext and one for the keyword
#AFTER: prints the encrypted version of the string
def encrypt(plainText,keyword):
    shift=[]
    containerString =""
    #Apparently in python strings are immutable so I have to  do this weird conversion just to be able to alter a string >:V
    mutablePlainText= list(plainText)
    mutableKeyWord=list(keyword)
    for index in range(0,len(keyword)):
        sValue = ord(mutableKeyWord[index])-97
        shift.append(sValue)

    k=0
    for index in range(0,len(plainText)):
        if(plainText[index]!= ' '):
            shiftLetterR(mutablePlainText,shift[k%len(keyword)],index)
            containerString+=mutablePlainText[index]
            k+=1


    print(containerString)

#The only change for this function is that it shifts to the left instead of to the right.

def decrypt(cipherText,keyword):
    shift=[]
    containerString =""
    #Apparently in python strings are immutable so I have to  do this weird conversion just to be able to alter a string >:V
    mutableCipherText= list(cipherText)
    mutableKeyWord=list(keyword)
    for index in range(0,len(keyword)):
        sValue = (ord(mutableKeyWord[index]))-97

        shift.append(sValue)
    k=0

    for index in range(0,len(cipherText)):
        if(cipherText[index]!= ' '):
            shiftLetterL(mutableCipherText,shift[k%len(keyword)],index)
            containerString+=mutableCipherText[index]
            k+=1

    print(containerString)
#################################################################
#Main
print("###Result of Encryption###")

plainText1="the warm sunshine filtered through the leaves of the trees casting dappled shadows on the ground below birds chirped and sang in the branches adding to the peaceful ambiance of the forest a light breeze rustled the leaves creating a gentle whispering sound that filled the air"
key1="engine"

encrypt(plainText1,key1)

plainText2="another text to try"
key2="secondkey"

encrypt(plainText2,key2)

plainText3="purple is the best city in the forest"
key3="passage"
encrypt(plainText3,key3)

print("")
print("###Result of Decryption###")
cipherText1 ="xizrmknurqjhgrlhyfuyayorcsaracwugrbwuaqmrfl"
keyWord1 ="funny"
decrypt(cipherText1,keyWord1)

cipherText2 ="tiesoisjbcbtpkofigtieehroeolvnqhfglhmpoaowgwny"
keyWord2 ="abandoned"
decrypt(cipherText2,keyWord2)
cipherText3= "kcbmfhbvsfefuoutxahtxwpqagpmoebgacysmwknurmjeizphruhaubrkwk"
keyWord3="domination"
decrypt(cipherText3,keyWord3)
"""
"""
#######################################################################
#Question3
#Two dimensional array, the columns are the letters in teh alphabet and the rows are equivalent to each letter in the key
import numpy as np
cypherText="Lbslrkszvgrtslrrzcxbzbmifwzdhohhvirqqdrgxfhifrzcfhlzcmajgzhbubdhjlhgmibomhprpaprvhnrrvhqirwgvseqglsbwvacgladxuhfdpvhgzuhdwmxorcjwgrfdmgvknsqhbeepdrdardhgiehraclhoqwbivhwgrfxfrfynrfsorwrugacjlhgterahwrvcepvwsqeebhqinviqifzohxvqussohrhwprjdvrgkhxulbrxrsdhrtwvqshjvslrffdexlbfhbrfnrrlgfvrhhdhobhgiffsmxbiofiqsooiedbcxuhgnjgpiqqhucetnjsrfrlbfxhubdhfxbkmtkhrxeholwgkfnytkrtwgbkhrqrkrgnvhhrtdkzvzjznahscmwuhzuifowmiqzwslorcjwbisuiebudrehwletlbzfyhwswnszzgrzvdvrwwlifwomhfvhhpydbcxuhctxflrdabuzcjngsrmawchrflummslqzrphorfbryksihfrpbvsslrpgdpihghrgksletlqnjfwcqcghzkmaj"

arr = np.zeros((26,5))

mutableCypherText= list(cypherText)

for index in range(0,len(cypherText)):
    arr[ord(mutableCypherText[index])-97][index%5]+=1

#This one prints it in matrix form however since I was asked to do it in vector form I will do it like this
#print(arr)
v1=[]
for index in range(0,26):
    v1.append(int(arr[index][0]))
v2=[]
for index in range(0,26):
    v2.append(int(arr[index][1]))
v3=[]
for index in range(0,26):
    v3.append(int(arr[index][2]))
v4=[]
for index in range(0,26):
    v4.append(int(arr[index][3]))
v5=[]
for index in range(0,26):
    v5.append(int(arr[index][4]))
print("v1:",v1)
print("v2:",v2)
print("v3:",v3)
print("v4:",v4)
print("v5:",v5)
print(" ")
decrypt(cypherText,"dozen")
"""
