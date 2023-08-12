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

    int len = strlen(text);

    int letters = count_letters(text);
    int words= count_words(text);
    int sentences = count_sentences(text);

    double L = 100.0 * ((double)letters/(double)words);
    double S = 100.0 * ((double)sentences/(double)words);

    double index = 0.0588 * L - 0.296 * S - 15.8;

    if(index < 1.0){
        printf("Before Grade 1");
    }
    else if(index > 16.0){
        printf("Grade 16+\n");
    }
    else{
        int grd;
        double x = index - (int)index;

        if(x > 0.5){
            grd = (int)index + 1;
        }
        else{
            grd = (int)index;
        }
        printf("Grade %d\n", grd);
    }

    return 0;
}