Useful git command line 

Cloning:
git clone  https://github.com/CGMcAllansmith/AVC_CLAP-TRAP_T12017
once ouve clones then update by typing git pull. 

cd AVC_CLAP-TRAP_T12017    //locates repository
git status
git add <the filename.md that you added/updated>  //Add files (updating step 1)
git commit -m "place your message here with quotations"  //Commit with comments (updating step 2)
git push      //Push (updating step 3)


If you forget to add a commit comment press >ESC>:>w>q

Creating branches:
rain-of-salt: [~/AVC_CLAP-TRAP_T12017] % git pull
                Already up-to-date.
grain-of-salt: [~/AVC_CLAP-TRAP_T12017] % git branch          //available branches
                * master
grain-of-salt: [~/AVC_CLAP-TRAP_T12017] % git branch Carls_work  //creates a branch called Carls_work (a copy of master)
grain-of-salt: [~/AVC_CLAP-TRAP_T12017] % git branch
                Carls_work
                * master
grain-of-salt: [~/AVC_CLAP-TRAP_T12017] % git checkout Carls_work   //now working in Carls_work
                Switched to branch 'Carls_work'
grain-of-salt: [~/AVC_CLAP-TRAP_T12017] % 
