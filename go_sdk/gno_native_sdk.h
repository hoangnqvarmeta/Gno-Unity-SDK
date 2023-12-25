/* Code generated by cmd/cgo; DO NOT EDIT. */

/* package command-line-arguments */


#line 1 "cgo-builtin-export-prolog"

#include <stddef.h>

#ifndef GO_CGO_EXPORT_PROLOGUE_H
#define GO_CGO_EXPORT_PROLOGUE_H

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef struct { const char *p; ptrdiff_t n; } _GoString_;
#endif

#endif

/* Start of preamble from import "C" comments.  */


#line 3 "api.go"

#include <stdint.h> // for uint32_t

// If crypto.Address and crypto.PubKey are fixed-size byte arrays, define their sizes
#define ADDRESS_SIZE 20 // Example size, adjust according to actual crypto.Address size
#define PUBKEY_SIZE  58 // Example size, adjust according to actual crypto.PubKey size

// Define a C-compatible KeyInfo struct
typedef struct {
	uint32_t Type;
	const char* Name;
	const uint8_t PubKey[PUBKEY_SIZE];
	const uint8_t Address[ADDRESS_SIZE];
} KeyInfo;

typedef struct {
	KeyInfo* Info;
	char* Password;
} UserAccount;

// Define the Coin type in C, assuming both Denom and Amount are strings
typedef struct {
    char *Denom;
    uint64_t Amount;
} Coin;

// If Coins is a dynamic array or slice of Coin, you will need a struct to represent it
typedef struct {
    Coin *Array;     // Pointer to the first Coin element
    size_t Length;   // Number of elements in the Coins array
} Coins;

// Then define the BaseAccount struct in C
typedef struct {
    uint8_t Address[ADDRESS_SIZE];
    Coins*   Coins;              // Assuming Coins is represented as above
    uint8_t PubKey[PUBKEY_SIZE];
    uint64_t AccountNumber;
    uint64_t Sequence;
} BaseAccount;

#line 1 "cgo-generated-wrapper"


/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */
#line 1 "cgo-gcc-export-header-prolog"

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef size_t GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
#ifdef _MSC_VER
#include <complex.h>
typedef _Fcomplex GoComplex64;
typedef _Dcomplex GoComplex128;
#else
typedef float _Complex GoComplex64;
typedef double _Complex GoComplex128;
#endif

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/
typedef char _check_for_64_bit_pointer_matching_GoInt[sizeof(void*)==64/8 ? 1:-1];

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef _GoString_ GoString;
#endif
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif

extern int SetRemote(char* remote);
extern char* GetRemote();
extern int SetChainID(char* chainID);
extern char* GetChainID();
extern char* GenerateRecoveryPhrase();
extern KeyInfo** ListKeyInfo(int* length);
extern int HasKeyByName(char* name);
extern int HasKeyByAddress(uint8_t* address, int len);
extern int HasKeyByNameOrAddress(char* nameOrBech32);
extern KeyInfo* GetKeyInfoByName(char* name);
extern KeyInfo* GetKeyInfoByAddress(uint8_t* address);
extern KeyInfo* GetKeyInfoByNameOrAddress(char* nameOrBech32);
extern KeyInfo* CreateAccount(char* nameOrBech32, char* mnemonic, char* bip39Passwd, char* password, int account, int index);
extern UserAccount* SelectAccount(char* nameOrBech32);
extern int SetPassword(char* password);
extern UserAccount* GetActiveAccount();
extern BaseAccount* QueryAccount(uint8_t* address);
extern int DeleteAccount(char* nameOrBech32, char* password, int skipPassword);
extern uint8_t* Query(char* path, uint8_t* data, int lenght, int* retLen);
extern char* Render(char* packagePath, char* args);
extern char* QEval(char* packagePath, char* expression);
extern uint8_t* Call(char* packagePath, char* fnc, char** args, char* gasFee, uint64_t* gasWanted, char* send, char* memo, int* retLen);
extern char* AddressToBech32(uint8_t* address);
extern uint8_t* AddressFromBech32(char* bech32Address);

#ifdef __cplusplus
}
#endif
