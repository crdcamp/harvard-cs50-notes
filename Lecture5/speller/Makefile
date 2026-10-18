speller:
	clang speller.c dictionary.c -o speller

debug_small: speller
	lldb ./speller -- dictionaries/small texts/cat.txt

debug_large: speller
	lldb ./speller -- dictionaries/large texts/cat.txt

clean:
	rm -f speller *.o
