#include <iostream>
#include "dotenv/dotenv.hpp"

int main()
{
    // dotenv::load takes the path to the directory
    // where the .env file is located
    dotenv::load("../.env");

    // Gets all Variables succesfully parsed from the .env file
    auto dot_env_vars = dotenv::get_variables();
    for (auto env_var : dot_env_vars)
    {
        // dotenv::getenv returns a std::optional object.
        // Since we know that these variables got set it's safe to call .value() on it
        std::cout << env_var << " = " << dotenv::get_env(std::string(env_var)).value() << "\n";
    }

    // dotenv::get_env can also be used to retrieve general environment variables.
    auto home_var = dotenv::get_env("HOME");
    if (home_var != std::nullopt)
    {
        std::cout << home_var.value() << "\n";
    }

    return 0;
}
