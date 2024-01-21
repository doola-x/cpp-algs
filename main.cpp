#include <iostream>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, string *userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    string rBuff;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/get");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &rBuff);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) { std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl; }
        else { std::cout << "Response data: " << rBuff << std::endl; }

        curl_easy_cleanup(curl);
    } 
    else 
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}