# CS2263 Assignment 4
- Rinor Komorani
- March 27th 2024
- Przemyslaw Rafal Pochec
<div style="page-break-after: always;"></div>

# Table of Contents
- [Question 1](#question-1)
- [Question 2](#question-2)
- [Question 3](#question-3)
- [Question 4](#question-4)
- [Question 5](#question-5)

<div style="page-break-after: always;"></div>

## Question 1
For my __htags3__ program, the logic of finding an opening tag, and continuing to do a certain operation until a closing tag was met; was the same as __htags2__.

The big difference here is that instead of using fixed data sizes, dynamic allocation for size was used on the heap.

I allocated my memory for __2__ data structures in my program. The first data structure consisted of a __1D array__ that stored enough space for a singular tag _(including a null terminating character)_

I would keep track of the space allocated each time a _'<'_ opening tag was met, and continuted counting the amount of space needed for 1 char until a _'>'_ closing tag was met. The count was reset once a new opening _'<'_ was met.

This way of counting helped me when I allocated space for my other data structure, a __2D array__. I used __realloc()__ for my rows in my data structure, adding memory for __1 char pointer__ if a tag was not yet seen (_using strings.h for comparasion_). I used __malloc()__ for each column of that new row to store the tag. The size I used to allocate that column memory came from my _1D array_ size counter.

<div style="page-break-after: always;"></div>

## Question 2

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// reads and frees elements of 2D array
void readArray(char ** array, int length)
{
    printf("\n");
    printf("Unique words between HTML tags:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%s\n", array[i]);
        free(array[i]);
    }
    free(array);
    printf("\n");
}

void readFile(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return;
    }

    bool inTag = false, inComment = false;
    int newAllocation = 0, c, totalAllocation = 0, totalToPrint = 0, index = 0, opener = '<', closer = '>', unique_words_count = 0;
    char * word = NULL, ** uniqueWord = NULL;

    while ((c = fgetc(file)) != EOF)
    {

        // inside opening tag
        if (c == '<')
        {
            c = fgetc(file);

            // check if next character is in comment or not
            if (c == '!')
            {
                inComment = true;
                continue;
            }
            else
            {
                // reset new word memory allocation
                newAllocation = 0;

                newAllocation += 2;
                totalAllocation += 2;

                inTag = true;

                // allocate new memory on heap of first 2 valid read-in chars
                // for the temp array
                word = malloc(newAllocation * sizeof(char));

                word[index++] = opener;
                word[index++] = c;
                continue;
            }
        }

        else if (c == '>')
        {
            if (inComment)
            {
                inComment = false;
                continue;
            }
            else 
            {
                newAllocation += 2;
                totalAllocation += 2;

                word = realloc(word, totalAllocation);             

                inTag = false;
                word[index++] = closer;
                word[index] = '\0';

                // printf("Current Allocation of tag %d bytes\n", newAllocation);

                // check if the word is unique
                bool found = false;
                for (int i = 0; i < unique_words_count; i++)
                {
                    // found word in 2D array
                    if (strcmp(word, uniqueWord[i]) == 0)
                    {
                        found = true;
                        break;
                    }
                }
                // store unique word in array of strings (2D)
                // using malloc (size of the current tag)
                if (!found) {
                    totalToPrint += newAllocation;
                    printf("Current allocated tag memory: %d\n", newAllocation);

                    // row implementation
                    uniqueWord = realloc(uniqueWord, (unique_words_count + 1) * sizeof(char *));

                    // col implementation
                    uniqueWord[unique_words_count] = malloc(newAllocation * sizeof(char)); 

                    // adding word to 2D array
                    strcpy(uniqueWord[unique_words_count], word);
                    unique_words_count++;
                }

                // reset counters & free temp word array
                index = 0;
                free(word);
            }
        }

        // still in word -- continue storing characters
        if (inTag && !inComment)
        {
            newAllocation++;
            totalAllocation++;

            word = realloc(word, totalAllocation);

            word[index++] = c;
        }
    }

    // print unique words & free uniqueWords allocation
    readArray(uniqueWord, unique_words_count);
    fclose(file);
    
    printf("Total allocated memory: %d bytes\n", totalToPrint);
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }

    readFile(argv[1]);

    return EXIT_SUCCESS;
}
```

## Question 3

```html
rinor@rinors-mac Assgn4 % ./htags3 test.html
Current allocated tag memory: 7
Current allocated tag memory: 4
Current allocated tag memory: 5
Current allocated tag memory: 8

Unique words between HTML tags:

<b>
</b>
</html>

Total allocated memory: 24 bytes

rinor@rinors-mac Assgn4 % 
```
<div style="page-break-after: always;"></div>

## Question 4

```html
rinor@rinors-mac Assgn4 % ./htags3 A4W2024.html
Current allocated tag memory: 7
Current allocated tag memory: 7
Current allocated tag memory: 73
Current allocated tag memory: 61
Current allocated tag memory: 8
Current allocated tag memory: 9
Current allocated tag memory: 8
Current allocated tag memory: 73
Current allocated tag memory: 25
Current allocated tag memory: 20
Current allocated tag memory: 4
Current allocated tag memory: 81
Current allocated tag memory: 8
Current allocated tag memory: 5
Current allocated tag memory: 5
Current allocated tag memory: 47
Current allocated tag memory: 63
Current allocated tag memory: 4
Current allocated tag memory: 62
Current allocated tag memory: 5
Current allocated tag memory: 57
Current allocated tag memory: 38
Current allocated tag memory: 5
Current allocated tag memory: 51
Current allocated tag memory: 163
Current allocated tag memory: 4
Current allocated tag memory: 52
Current allocated tag memory: 5
Current allocated tag memory: 165
Current allocated tag memory: 63
Current allocated tag memory: 52
Current allocated tag memory: 53
Current allocated tag memory: 53
Current allocated tag memory: 72
Current allocated tag memory: 172
Current allocated tag memory: 79
Current allocated tag memory: 54
Current allocated tag memory: 151
Current allocated tag memory: 5
Current allocated tag memory: 90
Current allocated tag memory: 7
Current allocated tag memory: 8
Current allocated tag memory: 8

Unique words between HTML tags:

<head>
<meta http-equiv=Content-Type content="text/html; charset=windows-1252">
<meta name=Generator content="Microsoft Word 15 (filtered)">
<style>
</style>
</head>
<body lang=EN-CA link=blue vlink="#954F72" style='word-wrap:break-word'>
<div class=WordSection1>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal style='text-align:justify'>
<span lang=EN-US
style='font-family:"Times New Roman",serif'>
<u>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</u>
<a href="https://www.educba.com/types-of-tags-in-html/">
<span style='text-decoration:
none'>
</a>
<span style='font-family:"Times New Roman",serif'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:0cm;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<i>
<span
style='font-family:"Times New Roman",serif'>
</i>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
<span lang=EN-US style='font-family:"Courier New"'>
<span
lang=EN-US style='font-family:"Courier New"'>
<span lang=EN-US
style='font-family:"Courier New"'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;line-height:12.0pt'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
<span lang=EN-US style='font-family:
"Courier New"'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
12.0pt;margin-left:43.1pt;text-indent:-18.0pt;line-height:12.0pt'>
<br>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'>
</div>
</body>
</html>

Total allocated memory: 1982 bytes

rinor@rinors-mac Assgn4 % 
```

<div style="page-break-after: always;"></div>

## Question 5

This is the output of the __htags2__ program from the downloaded Assignment 2 page:

### Input
```html
<html>

<head>
<meta http-equiv=Content-Type content="text/html; charset=unicode">
<meta name=Generator content="Microsoft Word 15 (filtered)">
<style>
<!--
 /* Font Definitions */
 @font-face
	{font-family:"Cambria Math";
	panose-1:2 4 5 3 5 4 6 3 2 4;}
@font-face
	{font-family:Calibri;
	panose-1:2 15 5 2 2 2 4 3 2 4;}
@font-face
	{font-family:Times;
	panose-1:0 0 5 0 0 0 0 2 0 0;}
 /* Style Definitions */
 p.MsoNormal, li.MsoNormal, div.MsoNormal
	{margin:0cm;
	font-size:12.0pt;
	font-family:Times;}
p.MsoBodyTextIndent, li.MsoBodyTextIndent, div.MsoBodyTextIndent
	{mso-style-link:"Body Text Indent Char";
	margin-top:0cm;
	margin-right:0cm;
	margin-bottom:0cm;
	margin-left:1.0cm;
	text-indent:-1.0cm;
	font-size:12.0pt;
	font-family:Times;}
a:link, span.MsoHyperlink
	{color:blue;
	text-decoration:underline;}
span.BodyTextIndentChar
	{mso-style-name:"Body Text Indent Char";
	mso-style-link:"Body Text Indent";
	font-family:Times;}
.MsoChpDefault
	{font-size:10.0pt;
	font-family:"Calibri",sans-serif;}
@page WordSection1
	{size:612.0pt 792.0pt;
	margin:72.0pt 90.0pt 72.0pt 90.0pt;}
div.WordSection1
	{page:WordSection1;}
-->
</style>

</head>

<body lang=EN-CA link=blue vlink=purple style='word-wrap:break-word'>

<div class=WordSection1>

<p class=MsoNormal><b><span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>CS 2263</span></b></p>

<p class=MsoNormal><b><span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>Assignment 2</span></b></p>

<p class=MsoNormal><b><span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>Due: Feb. 21, 2024 (before midnight) </span></b></p>

<p class=MsoNormal style='text-align:justify'><span lang=EN-US
style='font-family:"Times New Roman",serif'>_______________________________________________________</span></p>

<p class=MsoNormal><u><span lang=EN-US style='font-family:"Times New Roman",serif'>Assignments
are to be completed individually (<b>not</b> as a group work).</span></u></p>

<p class=MsoNormal><span lang=EN-US style='font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal><span lang=EN-US style='font-family:"Times New Roman",serif'>Sample
reference: <a href="https://www.educba.com/types-of-tags-in-html/"><span
style='text-decoration:none'>https://www.educba.com/types-of-tags-in-html/</span></a>
</span></p>

<p class=MsoNormal><span style='font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:0cm;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'><i><span
style='font-family:"Times New Roman",serif'>Processing strings</span></i></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'><span
lang=EN-US style='font-family:"Times New Roman",serif'>Develop and test two
utility programs called “htags1” and “htext1” to process an HTML file. The </span><span
lang=EN-US style='font-family:"Courier New"'>htags1</span><span lang=EN-US
style='font-family:"Times New Roman",serif'> program should &nbsp;print all
HTML tags, <b>except</b> the HTML comment tags &lt;!-- --&gt;, one per line of
output. The </span><span lang=EN-US style='font-family:"Courier New"'>htext1</span><span
lang=EN-US style='font-family:"Times New Roman",serif'> program should print
all plain text extracted from the source HTML file, i.e. just the text, no
tags. The utility programs should read form standard input and may use the <a
href="https://linuxcommand.org/lc3_lts0070.php">input redirection</a> to access
a file. (This means that your program code should read from standard input, and
NOT perform any file operations, like fopen() etc. You may capture the output
from your program using output redirection, or you may just output to the
terminal window and print the screen, your choice.)</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>Assume an
HTML tag is any text enclosed between &lt; and &gt;, including these delimiter
characters. The end tags, like &lt;/p&gt;, are valid tags. For example, in a
sample input HTML file containing:</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:25.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'><br>
&lt;body lang=EN-CA link=blue vlink=&quot;#954F72&quot;&gt;<br>
&lt;div class=WordSection1&gt;<br>
&lt;p class=MsoNormal&gt;&lt;b&gt;&lt;span lang=EN-US
style='font-size:14.0pt;font-family: &quot;Times New Roman&quot;,serif'&gt;CS
2263&lt;/span&gt;&lt;/b&gt;&lt;/p&gt;<br>
&lt;p class=MsoNormal&gt;&lt;b&gt;&lt;span lang=EN-US
style='font-size:14.0pt;font-family: &quot;Times New
Roman&quot;,serif'&gt;Assignment 2&lt;/span&gt;&lt;/b&gt;&lt;/p&gt;</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:25.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'><br>
we find the following tags: <br>
<br>
&lt;body lang=EN-CA link=blue vlink=&quot;#954F72&quot;&gt;<br>
&lt;div class=WordSection1&gt;<br>
&lt;p class=MsoNormal&gt;<br>
&lt;b&gt;<br>
&lt;span lang=EN-US style='font-size:14.0pt;font-family: &quot;Times New
Roman&quot;,serif'&gt; <br>
&lt;/span&gt;<br>
&lt;/b&gt;<br>
&lt;/p&gt;<br>
&lt;p class=MsoNormal&gt;<br>
&lt;b&gt;<br>
&lt;span lang=EN-US style='font-size:14.0pt;font-family: &quot;Times New
Roman&quot;,serif'&gt; <br>
&lt;/span&gt;<br>
&lt;/b&gt;<br>
&lt;/p&gt; <br>
<br>
and the plain text in this sample input is: <br>
<br>
CS 2263 Assignment 2</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'><span
lang=EN-US style='font-family:"Times New Roman",serif'><br>
When outputting the plain text you may keep new line characters present in the
input, or you may replace them with space characters. <br>
<br>
The data to your program should be read from standard input (use the input
redirection to read from the HTML file) using the </span><b><span lang=EN-US
style='font-family:"Courier New"'>getchar()</span></b><span lang=EN-US
style='font-family:"Times New Roman",serif'> function. The output should be
done using the </span><b><span lang=EN-US style='font-family:"Courier New"'>putchar()</span></b><span
lang=EN-US style='font-family:"Times New Roman",serif'> function and/or using
the </span><b><span lang=EN-US style='font-family:"Courier New"'>printArr()</span></b><span
lang=EN-US style='font-family:"Times New Roman",serif'> function from Assignment
1. You must use the </span><span lang=EN-US style='font-family:"Courier New"'>printArr()</span><span
lang=EN-US style='font-family:"Times New Roman",serif'> function at least once in
each utility program developed for this assignment. The Assignment Report
should consist of the following parts/exercises:</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>1.</span><span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span lang=EN-US style='font-family:"Times New Roman",serif'>In a few
sentences describe the design of the htags1 program. Focus on the description of
the algorithm used and of any data structures needed to complete the task.</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>2.</span><span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span style='font-family:"Times New Roman",serif'>Show the <u>complete</u>
source code for htags1.</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>3.</span><span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span lang=EN-US style='font-family:"Times New Roman",serif'>In a few
sentences describe the design of the htext1 program. Focus on the description of
the algorithm used and of any data structures needed to complete the task. </span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>4.</span><span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span style='font-family:"Times New Roman",serif'>Show the <u>complete</u>
source code for htext1.</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
12.0pt;margin-left:43.1pt;text-indent:-18.0pt;line-height:12.0pt'><span
lang=EN-US style='font-family:"Times New Roman",serif'>5.</span><span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span style='font-family:"Times New Roman",serif'>Show the output from
running htags1 and htext1 programs on the following input HTML code (store it
in a file and use input redirection to read): <br>
<br>
&lt;html&gt; &lt;b&gt; TEST &lt;/b&gt; &lt;/html&gt;</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>6.</span><span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span style='font-family:"Times New Roman",serif'>Show the output from
running htags1 and htext1 program on this HTML file, i.e. the very file
describing this assignment: you need to download this file separately from D2L
to your computer</span><span lang=EN-US style='font-family:"Times New Roman",serif'>
(do not download the entire D2L web page!). The file name is A2W2024.html.&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>7.</span><span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span style='font-family:"Times New Roman",serif'>Show the output from
running htags1 and htext1 program on another HTML file, of your choice.</span><span
lang=EN-US style='font-family:"Times New Roman",serif'>&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'><span lang=EN-US style='font-family:"Times New Roman",serif'>Submit a
SINGLE PDF FILE with your Assignment Report and it should include: a heading
for each exercise 1 to 7, including the source code of each completed program
and the screenshots of the terminal window (or the contents of the file with the
redirected program output) showing the test runs. In case of multiple
submission the most recent item in your Dropbox will be graded.</span></p>

<p class=MsoNormal><span lang=EN-US style='font-family:"Times New Roman",serif'>&nbsp;</span></p>

</div>

</body>

</html>
```
<div style="page-break-after: always;"></div>

### htags2 Output
```html
rinor@rinors-mac Assgn4 % ./htags3 test3.html  
Current allocated tag memory: 7
Current allocated tag memory: 7
Current allocated tag memory: 68
Current allocated tag memory: 61
Current allocated tag memory: 8
Current allocated tag memory: 9
Current allocated tag memory: 8
Current allocated tag memory: 70
Current allocated tag memory: 25
Current allocated tag memory: 20
Current allocated tag memory: 4
Current allocated tag memory: 80
Current allocated tag memory: 8
Current allocated tag memory: 5
Current allocated tag memory: 5
Current allocated tag memory: 47
Current allocated tag memory: 62
Current allocated tag memory: 4
Current allocated tag memory: 62
Current allocated tag memory: 5
Current allocated tag memory: 57
Current allocated tag memory: 36
Current allocated tag memory: 5
Current allocated tag memory: 51
Current allocated tag memory: 162
Current allocated tag memory: 4
Current allocated tag memory: 51
Current allocated tag memory: 5
Current allocated tag memory: 164
Current allocated tag memory: 62
Current allocated tag memory: 52
Current allocated tag memory: 52
Current allocated tag memory: 52
Current allocated tag memory: 168
Current allocated tag memory: 169
Current allocated tag memory: 5
Current allocated tag memory: 52
Current allocated tag memory: 170
Current allocated tag memory: 78
Current allocated tag memory: 150
Current allocated tag memory: 89
Current allocated tag memory: 7
Current allocated tag memory: 8
Current allocated tag memory: 8

Unique words between HTML tags:
=Content-Type content="text/html
ntent="text/html
<meta http-equive"
<meta name=Generator content="Microsoft Word 15 (filtered)">
<style>
</style>
</head>
<body lang=EN-CA link=blue vlink=purple style='word-wrap:break-word'>
<div class=WordSection1>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal style='text-align:justify'>
<span lang=EN-US
style='font-family:"Times New Roman",serif'>
<u>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</u>
<a href="https://www.educba.com/types-of-tags-in-html/">
<span
style='text-decoration:none'>
</a>
<span style='font-family:"Times New Roman",serif'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:0cm;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<i>
<span
style='font-family:"Times New Roman",serif'>
</i>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
<span
lang=EN-US style='font-family:"Courier New"'>
<span lang=EN-US style='font-family:"Courier New"'>
<a
href="https://linuxcommand.org/lc3_lts0070.php">
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:25.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'>
<br>
<span lang=EN-US
style='font-family:"Courier New"'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
12.0pt;margin-left:43.1pt;text-indent:-18.0pt;line-height:12.0pt'>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'>
</div>
</body>
</html>

Total allocated memory: 2222 bytes

rinor@rinors-mac Assgn4 % 
```