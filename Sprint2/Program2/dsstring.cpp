#include "dsstring.h"

DSString::DSString(){
    this->data = nullptr;
}

DSString::DSString(const char* originalChar){                               // 'originalChar' is a constant, can not change
    this->data = new char[strlen(originalChar) + 1];                        // create new 'data' array size of originalChar + 1('\0')
    strcpy(this->data,originalChar);                                        // c-copy 'originalChar' into 'data' array
}

DSString::DSString(const DSString& originaldsString){                       // Copy constructor, DSString parameter is a const,
    char * tempoData = this->data;
    this->data = new char[strlen(originaldsString.data) + 1];               // that goes by another name (&)
    strcpy(this->data,originaldsString.data);

    delete [] tempoData;
}

DSString::~DSString(){                                                      // destructor
    delete [] this->data;
}

DSString& DSString::operator=(const char* originalChar){                    // returns DSString& = originalChar
    char * tempData = this->data;

    this->data = new char[strlen(originalChar) + 1];
    strcpy(this->data,originalChar);                                        // copies originalChar to this->data

    delete [] tempData;
    return *this;                                                           // *this returns a reference to the object
}

DSString& DSString::operator=(const DSString& originalString){              // returns DSString& = originalString
    char * tempData = this->data;
    this->data = new char[strlen(originalString.data) + 1];
    strcpy(this->data,originalString.data);                                 // copies originalString.data to this->data

    delete [] tempData;
    return *this;                                                           // return DSString by reference
}

DSString DSString::operator+(const DSString& originalString){
    char * tempData = new char[strlen(this->data) + strlen(originalString.data) + 1];

    strcpy(tempData,this->data);
    strcat(tempData,originalString.data);
    DSString newString = tempData;

    delete [] tempData;
    return newString;                                                       // return DSString by value
}

DSString& DSString::operator+=(const DSString& originaldsString){
    char * tempChar = this->data;                                           // temporarily store this->data
    this->data = new char[strlen(tempChar) + strlen(originaldsString.data) + 1];    // empty out this->data
    strcpy(this->data,tempChar);                                            // copy tempChar to this->data
    strcat(this->data,originaldsString.data);                               // concatenate orginialString.data to this->data

    delete [] tempChar;

    return *this;                                                           // return a reference to invoking address
}

bool DSString::operator==(const char* parameterData) const{
    if(this->data == parameterData){
        return true;
    }
    else{
        return false;
    }

}

bool DSString::operator==(const DSString& parameterString) const{
    if(strcmp(this->data,parameterString.data) == 0){
        return true;
    }
    else{
       return false;
    }

}

bool DSString::operator<(const char * parameterChar) const{
    if(this->data < parameterChar){
        return true;
    }
    else if(this->data == parameterChar){
        for(int i = 0; i < int(strlen(this->data));i++){
            if(int(this->data[i]) > int(parameterChar[i])){
               return true;
            }
            else if(int(this->data[i]) < int(parameterChar[i])){
                return false;
            }
        }
    }
    return false;
}


bool DSString::operator<(const DSString& parameterDSString) const{
    if(this->data < parameterDSString.data){
        return true;
    }
    else if(this->data == parameterDSString.data){
        for(int i = 0; i < int(strlen(this->data));i++){
            if(int(this->data[i]) > int(parameterDSString.data[i])){
               return false;
            }
            else if(int(this->data[i]) < int(parameterDSString.data[i])){
                return true;
            }
        }
    }

    return true;

}

char& DSString::operator[](const int indexSize){
    return *(this->data + indexSize);
}

int DSString::size(){                                                       // return by value
    return int(strlen(this->data));
}

/*  Parameter a represents the starting position
 *  Parameter b represents the # of characters to copy into the substring that is returned.
 *  If b is (+), count forward from position a.
 *  If b is (-), count backward from position a.
 */
DSString DSString::substring(int a, int b){
    DSString aDSString;
    char * tempData = this->data;
    if(b > 0){
        if(a == 0){
            this->data = new char[int(b) + 1];
            //aDSString.data = new char[int(b) + 1];
            for(int i = 0; i < b; i++){
                //aDSString.data[i] = tempData[i];
                this->data[i]  = tempData[i];
            }
            //aDSString.data[int(b)] = '\0';
            this->data[int(b)] = '\0';
        }
        else if(a != 0){
            int c = (int(b) - a) + 1;
            this->data = new char[c + 1];
            //aDSString.data = new char[c + 1];
            for(int i = 0; i < c; i++){
                //aDSString.data[i] = tempData[a + 1];
                this->data[i]  = tempData[a + i];
            }
            this->data[c] = '\0';
            //aDSString.data[c] = '\0';
        }
        //aDSString.data = this->data;
        delete [] tempData;
        //this->data = tempData;
        return this->data; //aDSString;
    }

    else if(b < 0){
        char * tempData = this->data;
        int sizeOfChar = (b * -1) + 1;
        this->data = new char[sizeOfChar];
        for(int i = 0; i < -b ; i++){
            this->data[i] = tempData[(a + b) + i];
        }
        aDSString = this->data;

        delete [] tempData;
        return aDSString;
    }

    else{
        return aDSString;
    }
}

char* DSString::c_str(){                                                    // returns by pointer
    return this->data;
}

std::ostream& operator<<(std::ostream& out, const DSString& theString){
    out << theString.data;

    return out;
}

std::istream& operator>>(std::istream& stream,DSString& theString){
    char * tempChar = theString.data;
    theString.data = new char[100];

    if(stream.good()){
        while(!stream.eof()){
            stream >> *(theString.data);
        }
    }
    delete [] tempChar;
    return stream;
}
