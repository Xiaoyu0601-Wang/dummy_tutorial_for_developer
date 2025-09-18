- [Install git](#install-git)
- [Setting your user name and email address](#setting-your-user-name-and-email-address)
- [Generate Github SSH public key](#generate-github-ssh-public-key)
- [Rules for Git commit](#rules-for-git-commit)
- [Submission process](#submission-process)


# Install git
```sudo apt-get install git```

# Setting your user name and email address
git config --global user.name "YOUR_GITHUB_ID"
git config --global user.email "YOUR_REGUSTER_EMAIL"

# Generate Github SSH public key
Use the URL below to set the public key for SSH: https://docs.github.com/en/authentication
```sh
# Open Terminal. Paste the text below, replacing the email used in the example with your GitHub email address. Then press several times of "Enter".
ssh-keygen -t ed25519 -C "your_email@example.com"
```
Copy the content in .pub file. Then go to Github ```Settings``` -> ```SSH and PGP keys```, and click ```New SSH key``` to generate an Authentication key for your device.

# Rules for Git commit
1. Add new feature:```feat: xxxxxxxxxxxxxxx```
2. Fix bug: ```fix: xxxxxxxxxxxxxxx```
3. Refactor code:```chore: xxxxxxxxxxxxxxx```
4. Update .md content:```update: xxxxxxxxxxxxxxx```

# Submission process
1. Clone repository from github using ssh:
	```git clone xxxxxxxx```
2. Go to the repository directory, create and switch a new branch：
	```git checkout -b feat/xxxxxxx```
3. Modify the content according to the rules
4. Add your modifications and submit：
	```git add .```
	```git commit -m "feat: xxxxxx"```
5. Upload the modification branch to the github:
	```git push origin feat/xxxxxx```
6. Submit the merger request on GitHub, note the changes, and select the verifier. After the review is passed, confirm the merge and delete the branch.
7. Update your local repository
	```git pull origin main```

