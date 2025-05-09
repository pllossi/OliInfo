import string

# The encoded passphrase
encoded = "fiume-amico-casa-mare-{-amico-tempo-viaggio-mare-_-sole-tempo-montagna-giorno-viaggio-libro-_-sorriso-montagna-casa-viaggio-_-giorno-montagna-notte-porta-sogno-montagna-_-mare-fiume-strada-giorno-amico-vento-vento-mare-}"

# The same words list from the original code
words = [
    "casa", "albero", "notte", "sole", "montagna", "fiume", "mare", "vento", "nuvola", 
    "pioggia", "strada", "amico", "sorriso", "viaggio", "tempo", "cuore", "stella", 
    "sogno", "giorno", "libro", "porta", "luce", "ombra", "silenzio", "fiore", "luna"
]

# Create a mapping from word to letter
word_to_letter = {}
for i, word in enumerate(words):
    letter = chr(ord('a') + i)
    word_to_letter[word] = letter

# Split the encoded string
parts = encoded.split('-')

# Decode each part
flag = ""
for part in parts:
    if part in word_to_letter:
        flag += word_to_letter[part]
    else:
        flag += part

print(flag)