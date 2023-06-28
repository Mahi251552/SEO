#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

int get_backlink_count(string domain) {
  // Gets the backlink count for a domain.
  CURL *curl;
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.moz.com/linkscape/v1/backlinks/" + domain);
    curl_easy_setopt(curl, CURLOPT_RETURNTRANSFER, 1);
    string response = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    // Parses the response and returns the backlink count.
    json data = json::parse(response);
    return data["backlinks"];
  } else {
    return 0;
  }
}

int main() {
  string domain = "www.example.com";
  int backlink_count = get_backlink_count(domain);
  cout << backlink_count << endl;

  return 0;
}
