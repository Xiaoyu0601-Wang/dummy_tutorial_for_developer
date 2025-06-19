- [Install git](#install-git)
- [Setting your user name and email address](#setting-your-user-name-and-email-address)
- [Rules for Git commit](#rules-for-git-commit)
- [Submission process](#submission-process)


# Install git
```sudo apt-get install git```

# Setting your user name and email address
git config --global user.name "Mona Lisa"
git config --global user.email "YOUR_EMAIL"

# Rules for Git commit
1. Add new feature:```feat: xxxxxxxxxxxxxxx```
2. Update content:```update: xxxxxxxxxxxxxxx```
3. Fix bug: ```fix: xxxxxxxxxxxxxxx```

# Submission process
1. Clone repository from github:
	```git clone xxxxxxxx(SSH)```
2. Move to the file directory and create a branch：
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

