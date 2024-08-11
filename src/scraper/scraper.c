#include "../../include/imports.h"

#include <curl/curl.h>
#include <stdio.h>

// https://aur.archlinux.org/rpc/?v=5&type=search&arg=package-name

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int Scraper(char* PackageName)
{
    FILE* OutputFile;
    CURL* Handle;
    char Buf[8192];

    static const char* Filename = "results.txt";
    
    curl_global_init(CURL_GLOBAL_ALL);
    Handle = curl_easy_init();

    snprintf(Buf, sizeof(Buf), "https://aur.archlinux.org/rpc/?v=5&type=search&arg=%s", PackageName);

    curl_easy_setopt(Handle, CURLOPT_URL, Buf);
    curl_easy_setopt(Handle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(Handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(Handle, CURLOPT_WRITEFUNCTION, write_data);
    
    OutputFile = fopen(Filename, "wb");

    if(OutputFile)
    {
        curl_easy_setopt(Handle, CURLOPT_WRITEDATA, OutputFile);
        curl_easy_perform(Handle);
    
        fclose(OutputFile);
    }

    curl_easy_cleanup(Handle);
    curl_global_cleanup();

    PrettyPrinter();
    FiltreResults();
    return 0;
}

