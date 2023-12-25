using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

namespace Gno.Unity.Sample.UI
{
    public class GnoUILink : MonoBehaviour
    {
        static public GnoUILink Instance { get; set; }

        [HideInInspector]
        public string mnemonicsKey = "MnemonicsKey";
        [HideInInspector]
        public string privateKey = "PrivateKey";
        [HideInInspector]
        public string currentAddressIndexKey = "CurrentAddressIndexKey";

        [SerializeField] private int accountNumLimit = 10;
        public List<string> addressList;

        public event Action<float> onGetBalance;
        public static class Constants
        {
            public const int PUBKEY_SIZE = 58;
            public const int ADDRESS_SIZE = 20;
        }
        [StructLayout(LayoutKind.Sequential)]
        public struct KeyInfo
        {
            public uint Type;
            [MarshalAs(UnmanagedType.LPStr)]
            public string Name;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = Constants.PUBKEY_SIZE)]
            public byte[] PubKey;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = Constants.ADDRESS_SIZE)]
            public byte[] Address;
        }
        public static string ByteArrayToHexString(byte[] bytes)
        {
            return BitConverter.ToString(bytes).Replace("-", "").ToLower();
        }
        //private Wallet wallet;
        private string faucetEndpoint = "https://faucet.devnet.aptoslabs.com";

        private void Awake()
        {
            Instance = this;
        }

        void Start()
        {

        }

        void Update()
        {

        }


        public bool CreateNewWallet()
        {

            string mnemo = SDKWrapper.GenerateRecoveryPhrase();
            PlayerPrefs.SetString(mnemonicsKey, mnemo.ToString());
            PlayerPrefs.SetInt(currentAddressIndexKey, 0);

            GetWalletAddress();
            //LoadCurrentWalletBalance();

            if (mnemo.ToString() != string.Empty)
            {
                return true;
            }
            else
            {
                return false;
            }
        }



        public List<string> GetWalletAddress()
        {
            addressList = new List<string>();
            string mnemonics = PlayerPrefs.GetString(mnemonicsKey);

            // Check if mnemonic code is present and has length greater than 0.
            if (!string.IsNullOrEmpty(mnemonics))
            {
                // Default account name.
                string cname = "testKey";
                // Determine the index for the new account.
                int index = 0;

                // Create another account with the given name and mnemonic.
                IntPtr keyInfoPtr = SDKWrapper.CreateAccount(cname, mnemonics, "", "", index, index);
                if (keyInfoPtr != IntPtr.Zero)
                {
                    KeyInfo keyInfo = Marshal.PtrToStructure<KeyInfo>(keyInfoPtr);
                    string addressString = ByteArrayToHexString(keyInfo.Address);
                    addressList.Add(addressString);

                }

                // Refresh the key list to show the new account.
            }
            else
            {
                Debug.LogError("Missing mnemonic code.");
            }

            return addressList;
        }



    }
}