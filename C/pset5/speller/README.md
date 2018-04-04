# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

the longest word in Pset5 dictionary, we use it to check our code .

## According to its man page, what does `getrusage` do?

returns resource usage statistics , where it returns "who" parameter value ,and who contents the sum of resources used.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 members

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

because by value passing takes up a lot of memory and make our program more slow .
that is why , we depend on reference, by that , we save memory and make our program quickly .

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

the 'main' reads the file than by while loop our code reads from the file word by word than, we can using a for loop to read letter by letter
and our limit will be the length of the word, we must observe the charachter cassensetive and if it was a apostrophe and depend of that we can determin the index of this letter inside our array so on so forth until the while loop reaches to the end of the file.
it is added to a word. If the word becomes larger than what we have defined as the largest word possible, the word is
ignored. If the word has a digit, it is ignored also.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?
Actually I used the fscanf function and it was good and I felt that was more quickly than read charachter by charachter with fgetc
but maybe if we read the file characters by characters that will help us to check the another kind of charachter as apostrophe
in better accuracy. because the check will be more guaranteed.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?
we declared the parameters for we work in cpreatlly way in the scop of the particualr function , and we dont want to change the
orginal value of the varibles . that is way . we work depend on copy of the orginal varibles by these parameters
