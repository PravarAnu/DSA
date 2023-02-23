#include <iostream>
#include <regex>
using namespace std;

/*
    ---> In pattern matching we use metacharacters.
    ---> These metacharacters in c++ are:
    ---> ^ $ \ . * + ? () [] {} |
*/

int main() {

    // CHARACTER CLASSES

    // [] ---> Square Brackets
    // [] is used for range searching
    // for lowercase [a-z] or [abcdefghijklmnopqrstuvwxyz]
    // for uppercase [A-Z] or [ABCDEFGHIJKLMNOPQRSTUVWXYZ]
    // for digits [0-9] or [0123456789]
    string sentence1 = "The cat is dancing on the table";
    string sentence2 = "The bat is roaming inside the room";
    string sentence3 = "The rat is jumping in the kitchen";

    regex reg("[br]at");

    if (regex_search(sentence1, reg)) {
        cout << "The cat is found\n"; // This will not run
    }

    if (regex_search(sentence2, reg)) {
        cout << "The bat is found\n"; // This will run
    }

    if (regex_search(sentence3, reg)) {
        cout << "The rat is found\n"; // This will run
    }

    string sentence4 = "You can use ID6aD for your gate pass";
    regex match("ID[0-9]aD");
    /*
        Here we are trying to find if there a number exist between "ID" and "ad"
        then it is valid.
    */
    if (regex_search(sentence4, match)) {
        cout << "ID found\n";
    }

    /*
        ^ ---> Negation
        ^ is used as none of the characters in the set should match.

        Ex - [^0-9] means not includes any numbers 0 to 9 inclusive.

        You can also use any type of patterns:
            [^a-z], [^A-Z], [^cbr],.....
    */

    string sentence5 = "0123456789";
    regex match5("[^0-9]");

    if (regex_search(sentence5, match5)) {
        cout << "There are no numbers in the sentence\n";
    } else {
        cout << "There are numbers in the sentence\n";
    }

    /*
        Matching White Space
        In c++ there are some of the whitespace characters:
            \t --> tab
            \n --> new line
            \r --> carraige
            \f --> from feed

        Ex - [\t\r\f\n], "\n", "\t",....
    */

    /*
        MATCHING REPETITION
            * ---> matches a character repetiting 0 or more times
            Ex- x* : means match 'x' 0 or more times. i.e Any number of times

            + ---> matches a character repetiting 1 or more times
            Ex- x+ : means match 'x' 1 or more times. i.e At least once

            ? ---> matches a character 0 or 1 time
            Ex- x? : means match 'x' 0 or 1 time

            {n} ---> matches a character exactly n times
            Ex- x{3} : means match 'x' exactly 3 times

            {n,m} ---> matches a character at least n times, but not more than m
       times, Ex- x{2,3} : means match 'x' atleast 2 times but not more than 3
       times

            {n,} ---> matches a character at least n times or more than n times.
            Ex- x{3,} : means match 'x' at least 3 or more times.
    */

    cout << "For *: " << endl;
    regex star("o*");
    cout << regex_search("dog", star) << endl;   // returns true
    cout << regex_search("book", star) << endl;  // returns true
    cout << regex_search("boooo", star) << endl; // returns true
    cout << regex_search("cat", star)
         << endl; // returns true because * means 0 or more.

    cout << "For +: " << endl;
    regex plus("e+");
    cout << regex_search("eat", plus) << endl;   // returns true
    cout << regex_search("sheep", plus) << endl; // returns true
    cout << regex_search("dig", plus)
         << endl; // returns false because +  means 1 or more

    cout << "For ?: " << endl;
    regex question("m?");
    cout << regex_search("mug", question) << endl; // returns true
    cout << regex_search("bug", question)
         << endl; // returns true because ? means 0 or 1 time

    cout << "For {}: " << endl;
    regex curly1("o{2}");
    cout << regex_search("boom", curly1) << endl;   // returns true
    cout << regex_search("boooom", curly1) << endl; // returns true
    cout << regex_search("tom", curly1)
         << endl; // returns false because {n} means exactly n times

    regex curly2("o{2,}");
    cout << regex_search("boom", curly2) << endl;  // returns true
    cout << regex_search("booom", curly2) << endl; // returns true
    cout << regex_search("tom", curly2)
         << endl; // returns false because {n,} means n or more times

    regex curly3("o{2,5}");
    cout << regex_search("boom", curly2) << endl;        // returns true
    cout << regex_search("booooooooom", curly2) << endl; // returns true
    cout << regex_search("tom", curly2)
         << endl; // returns false because {n,m} means at least n or at most m
                  // times


    /*
        Matching Alternation --> It can be matched using | symbol which is also known as or

        Ex- "ram|shayam|bam" Here it matches for either ram or shyam or bam.
    */

    string sentence6 = "These cages are made for the lion";
    regex findingOr("lion|tiger|leopard"); // Here it searches for either lion or tiger or leopard

    cout<<regex_search(sentence6, findingOr)<<endl;    //returns true



    /* 
        Matching Beginning and Ending

        Beginning can be done using ^
        Ending can be done using $

    */

    cout<<regex_search("abc and def",regex("^abc"))<<endl;    //returns true
    cout<<regex_search("def and abc",regex("^abc"))<<endl;    //return false
    
    cout<<regex_search("abc and xyz",regex("xyz$"))<<endl;    //returns true
    cout<<regex_search("abc and xyz",regex("abc$"))<<endl;    //return false


    return 0;
}