
## Github
### Github SSH PublicKey
Use the URL below to set the public key for SSH: https://docs.github.com/en/authentication
```sh
cd ~/.ssh
ssh-keygen -t rsa -f id_rsa_github
gedit ~/.ssh/id_rsa_github.pub
```

### Github Submodule
```sh
# Add submodule
git submodule add https://github.com/raspberrypi/pico-examples.git pico-examples
# Remove submodule
git rm --cached pico-examples
```