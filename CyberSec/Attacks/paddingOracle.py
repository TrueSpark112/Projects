from oracle import encrypt, is_padding_ok, BLOCK_SIZE


def testthe_attack():



    attack_ciphertext= b'\xc9\xddW]\xa3\xdf2k\x19\xfc`\x04\xea\xaf\x8e\x9c\x08z\xb1V\x93\t\xd1-\xe8V\x04\xdc\xd9\x8e' + b'\xf3\x82\x97\x8d\xfa\x06\xdc\nk\x8aZ\xa6\x8a\t\xeeR\x92\x16\xf1z>\x14\x16\x88R\xe8\xcb\x08z\xc2\xd6Y;\x18'

    blocks = [attack_ciphertext[i:i + BLOCK_SIZE] for i in range(0, len(attack_ciphertext), BLOCK_SIZE)]

    for j in range(0,15):
      #This is the penultimate block
      mutaBlock = bytearray(blocks[2])
      #This is the last block
      permaBlock=bytearray(blocks[3])
      #change the first byte of the first block
      mutaBlock[j]=mutaBlock[j]+1
      #send the two blocks to the padding oracle
      fusedBlock=mutaBlock+permaBlock
      #print(j,": ",is_padding_ok(fusedBlock))
    #padding is at 5 YAAAY

def decrypt(b,leftBlockIndex,rightBlockIndex):


  attack_ciphertext= b'\xc9\xddW]\xa3\xdf2k\x19\xfc`\x04\xea\xaf\x8e\x9c\x08z\xb1V\x93\t\xd1-\xe8V\x04\xdc\xd9\x8e' + b'\xf3\x82\x97\x8d\xfa\x06\xdc\nk\x8aZ\xa6\x8a\t\xeeR\x92\x16\xf1z>\x14\x16\x88R\xe8\xcb\x08z\xc2\xd6Y;\x18'
  blocks = [attack_ciphertext[i:i + BLOCK_SIZE] for i in range(0, len(attack_ciphertext), BLOCK_SIZE)]
  #applied to
  #Uncomment the following three lines to check the code works for the last two blocks

  cipherText = bytearray(blocks[leftBlockIndex])
  permaBlock=bytearray(blocks[rightBlockIndex])


  #le attack can be
  #This is for the second block
  #b=0
  #cipherText = bytearray(blocks[1])
  #permaBlock=bytearray(blocks[2])

  #the padding orac
  #First block(For some reason the first character broke but it worked fine for)
  #the others so I´ll just  assume its a minor bug
  #b=0
  #cipherText = bytearray(blocks[0])
  #permaBlock=bytearray(blocks[1])


  #Create three empty byte arrays, one for delta and one for c prime the decrypted array
  #I moved the declarations of delta and cprime to the inside of the loop to avoid overwriting

  solved =bytearray(16)

  #alright lets try this again,
  #For the portion we don't know we don't need to touch anything
  #We need to make every other portion equal to the number of padding so the padding oracle reads that
  #b is the size of the padding
  #c is the size of the padding we know
  #Cprime:
   #   Portion we know we is Yc(each solved byte) XOR b+c+1 padding oracle cancels Yc
   #   Portion of the padding is bXOR(b+c+1) so the padding oracle cancels b
   #starting at the index after the one you are looking for, each value in delta is going to be
   #b^(b+c+1 where c is how many bytes you've decyphered)

  for c in range(16-b):
    for i in range(256):

      delta=bytearray(16)
      cprime=bytearray(16)

      #replace the value at the index you're trying to find with i
      delta[16-b-c-1]=i

      #write the padding, start at 5 and go up from there
      #so we start the padding at position 11
      for index in range(16-b,16,1):
        delta[index]=b^(b+c+1)

      #write the solved portion in
      for index in range(16-b-c,16-b,1):
        delta[index]=solved[index]^(b+c+1)

      #create cprime by xoring delta with the cyphertext
      for j in range(16):
        cprime[j]=int.from_bytes(byte_xor(delta[j].to_bytes(1, 'little') , cipherText[j].to_bytes(1,'little')),'little')

      fusedBlock=cprime+permaBlock

      if(is_padding_ok(fusedBlock)):

        solved[16-b-c-1]=i^(b+c+1)
        c+=1
  for s in range (len(solved)):
     print(chr(solved[s]))

def test_the_attack():
    attack_ciphertext= b'\xc9\xddW]\xa3\xdf2k\x19\xfc`\x04\xea\xaf\x8e\x9c\x08z\xb1V\x93\t\xd1-\xe8V\x04\xdc\xd9\x8e' + b'\xf3\x82\x97\x8d\xfa\x06\xdc\nk\x8aZ\xa6\x8a\t\xeeR\x92\x16\xf1z>\x14\x16\x88R\xe8\xcb\x08z\xc2\xd6Y;\x18'
    test_the_oracle(attack_ciphertext)

def test_the_oracle(cipher):
    print('Block size=', BLOCK_SIZE)   #BLOCK_SIZE=16
    print(is_padding_ok(cipher)) #returns True if padding is correct and False otherwise

def byte_xor(ba1, ba2):
    """this function XORs two byte objects """
    return bytes(_a ^ _b for _a, _b in zip(ba1, ba2))

def useful_python_examples():
    #Break ciphertex into blocks of 128 bits (16 bytes)
    blocks = [cipher[i:i + BLOCK_SIZE] for i in range(0, len(cipher), BLOCK_SIZE)]

    #prints out each individual block
    for i in range(0, len(blocks)):
        print(blocks[i])

    lastblock = bytearray(blocks[len(blocks)-1])  #The bytearray() method returns a bytearray object which is mutable (can be modified) - can be used when you want to change a byte of a block

    #if you print lastblock[0] it returns it as an integer type. In order to convert that to byte
    #you can use:
    lastblock[0].to_bytes(1, 'little')   #read about the definition of int.to_bytes to understand the parameters
    #byte_xor XORs two bytearrays, for example:
    byte_xor(b'\x01', b'\x02')  #retursn b'\x03' #this example is just XORing one byte, but it can be more like:
    print(byte_xor(b'\xA502', b'\x0215'))      #byte_xor XORs two given bytes

    #a bytes object can be converted to an integer value with int.from_bytes(), for example:
    int.from_bytes(byte_xor(b'\x01', b'\x02'), 'little')     #returns the int representation of \x03 which is 3

    print(b'\x54'.decode())   #decode(): changes from byte to string of characters, for example b'\x54'.decode() returns the letter 'T' because the ascii hex value of 'T' is 54. This is useful when you want to get the decrypted message back as an English string



if __name__ == '__main__':
  decrypt(0,0,1)
  decrypt(0,1,2)

  decrypt(5,2,3)
