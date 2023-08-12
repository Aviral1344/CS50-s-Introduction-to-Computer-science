#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text){
    int len = strlen(text);
    int count = 0;
    for(int i=0; i<len; i++){
        if((text[i] >= 'a' && text[i] <= 'z' )|| (text[i] >= 'A' && text[i] <= 'Z')){
            count++;
        }
    }
    return count;
}

int count_words(string text){
    int len = strlen(text);
    int count = 0;
    for(int i=0; i<len; i++){
        if(text[i] == ' ' && (text[i-1] == '.' || text[i-1] == '!' || text[i-1] == '?')){
            continue;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == ' '){
            count++;
        }
    }
    return count;
}

int count_sentences(string text){
    int len = strlen(text);
    int count = 0;
    for(int i=0; i<len; i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            count++;
        }
    }
    return count;
}

int main(void)
{
    string text = get_string("Text: ");

    int words = 0;
    int letters = 0;
    int sentences = 0;

    int len = strlen(text);

    int L = count_letters(text);
    int W = count_words(text);
    int S = count_sentences(text);

    double index = 0.0588 * (double)L - 0.296 * (double)S - 15.8;

    if(index < 1.0){
        printf("Before Grade 1");
    }
    else if(index > 16.0){
        printf("Grade 16+");
    }
    else{
        printf("Grade %d", (int)index);
    }

    return 0;
}