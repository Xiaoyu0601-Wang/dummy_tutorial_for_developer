- [Install git](#install-git)
- [Setting your user name and email address](#setting-your-user-name-and-email-address)
- [Generate Github SSH public key](#generate-github-ssh-public-key)
- [Rules for Git commit](#rules-for-git-commit)
- [Submission process](#submission-process)
- [Common used command](#common-used-command)


# Install git
```sudo apt-get install git```

# Setting your user name and email address
第一次使用 Git 时，需要设置用户名和邮箱，以便提交记录中显示
```sh
# Set global user name
git config --global user.name "YOUR_GITHUB_ID"
# Set global email address
git config --global user.email "YOUR_REGUSTER_EMAIL"
# Check configuration
git config --list
```

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
4. Add your modifications and submit:
	```git add .```
5. Add you commit content:
	```git commit -m "feat: xxxxxx"```
6. Upload the modification branch to the github:
	```git push origin feat/xxxxxx```
7. Submit the merger request on GitHub, note the changes, and select the verifier. After the review is passed, confirm the merge and delete the branch.
8. Update your local repository from `main`:
	```git pull origin main```

# Rules for Github PR
1. PR title should be like ```feat: xxxxxxxxxxxxx```
2. If one PR is cherry-pick, then title should be like ```feat(cherry-pick): xxxxxxxxxxx```
3. Don't forget to write some descriptions.
4. If possible, don't submit too much modifications in one PR.

# Common used command
```sh
# 克隆仓库
git clone https://github.com/用户名/仓库名.git
# 添加修改暂存区
git add 文件名       # 添加单个文件
git add .           # 添加当前目录下所有修改
# 提交修改
git commit -m "提交说明"
#推送到github
git push origin 分支名
#拉取更新
git pull origin 分支名
#分支管理
# 查看本地分支
git branch
# 创建新分支
git checkout -b 新分支名
# 切换分支
git checkout 分支名
# 合并分支
git merge 分支名
# 删除本地分支
git branch -d 分支名
# 删除远程分支
git push origin --delete 分支名
```
