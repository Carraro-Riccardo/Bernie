#include "Account.h"

Account::Account(const std::string & n, const std::string & email, const std::string & pswd, const std::string & usrnm): SerializableObject(n), email(email), username(usrnm), password(pswd){}
Account::Account(std::vector<std::string> serializedVectorized): SerializableObject(serializedVectorized[1]), email(serializedVectorized[2]),password(serializedVectorized[3]),username(serializedVectorized[4]) {}

std::string Account::serialize() const {
    std::string serializedObj = "ACCOUNT";
    serializedObj += SerializableObject::SEPARATOR;
    serializedObj = serializedObj + sanitize(name) + SerializableObject::SEPARATOR + sanitize(email) + SerializableObject::SEPARATOR + sanitize(password) + SerializableObject::SEPARATOR + sanitize(username);

    return serializedObj;
}

Account* Account::clone() const {
    return new Account(*this);
}