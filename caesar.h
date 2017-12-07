void check_magic_number(void);

/* \brief Encrypt a string with a right shift specified by the user
   \param [in] str The string to encrypt
   \param [in] len The length of the string str
   \param [in] d The right shift to perform
   \return The pointer to the encrypted string
*/
char *encrypt(char *str, int len, int d);

/* \brief Decrypt a string with a left shift specified by the user
   \param [in] str The string to decrypt
   \param [in] len The length of the string str
   \param [in] d The left shift to perform
   \return The pointer to the decrypted string
*/
char *decrypt(char *str, int len, int d);
