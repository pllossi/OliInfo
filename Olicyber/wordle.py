def vigenere_decrypt(ciphertext, key):
	plaintext = ""
	key_length = len(key)
	key_as_int = [ord(i) for i in key]
	
	for i in range(len(ciphertext)):
		if ciphertext[i].isalpha():
			# Get the right key character to use
			key_index = i % key_length
			# Convert the letter to a number from 0-25
			char_code = ord(ciphertext[i].lower()) - ord('a')
			# Apply Vigenère decryption formula
			decrypted = (char_code - key_as_int[key_index] + 26) % 26
			# Convert back to letter
			plaintext += chr(decrypted + ord('a'))
		else:
			# If not a letter, keep the character as is
			plaintext += ciphertext[i]
	
	return plaintext

# Test the decryption
encrypted_text = "cyvz{dmtrfqpnsrk_vmu_aqmx_fq_au_amqeux}"
key = "wordle"

print("Encrypted text:", encrypted_text)
decrypted_text = vigenere_decrypt(encrypted_text, key)
print("Decrypted text:", decrypted_text)
