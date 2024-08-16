#include "../include/urls.h"

#include <curl/curl.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

void Curl(const char URL[], const char FILE_NAME[])
{
    FILE* OutputFile;
    CURL* Handle;

    curl_global_init(CURL_GLOBAL_ALL);
    Handle = curl_easy_init();

    curl_easy_setopt(Handle, CURLOPT_URL, URL);
    curl_easy_setopt(Handle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(Handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(Handle, CURLOPT_WRITEFUNCTION, write_data);

    OutputFile = fopen(FILE_NAME, "wb");

    if(OutputFile)
    {
        curl_easy_setopt(Handle, CURLOPT_WRITEDATA, OutputFile);
        curl_easy_perform(Handle);

        fclose(OutputFile);
    }

    curl_easy_cleanup(Handle);
    curl_global_cleanup();
}

