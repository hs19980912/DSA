int circularDistance = (posB - posA + 26) % 26;


Given 2 strings, return if they are buddies. 
2 strings are buddies if the distance between each char of the strings is the same. 
dist('a', 'b') = 1
dist('b', 'a') = 25
dist('z', 'a') = 1


====================================================================================

int circularDistance(char a, char b) {
    int posA = a - 'a';
    int posB = b - 'a';
    
    // Calculate forward distance (a to b)
    int forwardDist = (posB - posA + 26) % 26;
    
    return forwardDist;
}

bool areBuddies(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    
    if (str1.empty()) {
        return true;
    }
    
    int requiredDistance = circularDistance(str1[0], str2[0]);
    
    for (size_t i = 1; i < str1.length(); i++) {
        if (circularDistance(str1[i], str2[i]) != requiredDistance) {
            return false;
        }
    }
    
    return true;
}