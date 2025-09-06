#John Kimak
#Files

def main():
    #defaults to read mode
    with open("") as my_file:
        _256_bytes = my_file.read(256)
        my_file.read()
        my_file.readlines()
        my_file.readline()
        for line in my_file:
            print(line)

   
main()