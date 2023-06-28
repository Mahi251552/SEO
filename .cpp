#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_keyword_suggestions(string keyword) {
  // Gets keyword suggestions from Google Keyword Planner.
  string url = "https://api.google.com/keywordplanner/v1/keywords/autocomplete";
  string params = "key=YOUR_API_KEY&q=" + keyword;
  string response = "";
  try {
    response = requests::get(url + "?" + params).content;
  } catch (requests::RequestException e) {
    cout << "Error: " << e.what() << endl;
    return {};
  }

  // Parses the response and returns a vector of keyword suggestions.
  vector<string> suggestions;
  try {
    json data = json::parse(response);
    suggestions = data["suggestions"];
  } catch (json::exception e) {
    cout << "Error: " << e.what() << endl;
    return {};
  }

  return suggestions;
}

int main() {
  string keyword = "keyword research";
  vector<string> suggestions = get_keyword_suggestions(keyword);
  for (string suggestion : suggestions) {
    cout << suggestion << endl;
  }

  return 0;
}

