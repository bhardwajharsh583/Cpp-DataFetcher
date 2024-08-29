📦 C++ Datafetcher

A C++ project that fetches and parses JSON data from a URL using curl and nlohmann/json. Built with CMake for easy cross-platform compilation.

🚀 Features

1. Fetch Data: Retrieve data from a URL using curl.
2. JSON Parsing: Parse JSON data effortlessly with nlohmann/json.
3. Custom Build System: Built using CMake with MinGW as the generator for easy cross-platform builds.
4. User-Friendly CLI: Choose from multiple options to retrieve and display specific data from the JSON response.

📚 Dependencies
This project uses the following libraries:

1. nlohmann/json for JSON parsing.
2. curl for data fetching.
Note: All dependencies are included within the project directory, making it easier to build and run on any system without needing to install them separately.

🛠️ Steps Followed to build:
Follow these steps to build and run the project:

1. First created the structure of the project and downloaded the dependencies (I have not added dependency in my system but rather here in the project so it become easier to build if anyone wants to).
2. Dependencies include: nlohmann/json and curl.
3. Created CMakeLists.txt [ Including the dependencies was the main part ]
4. Created build folder and cd into it
5. Ran: cmake -G "MinGW Makefiles" ..
6. Ran: mingw32-make to create executable
7. Code has 3 options to choose what you want to retrieve from the url which user can choose while running the executable by choosing the appropriate flags:
   
   a. --versions will print the list of versions from the json

   b. --ltsversion will print a single string from the json

   c. --sha256 will print single string denoting sha256 key from the json

🛠️ Run:

./JsonFetcher.exe --versions

./JsonFetcher.exe --ltsversion

./JsonFetcher.exe --sha256

📦 Outputs
The outputs are based on the selected command-line option and are displayed directly in the terminal.
