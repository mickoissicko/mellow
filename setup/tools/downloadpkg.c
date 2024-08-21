#include "../../include/setup.h"
#include "../../include/urls.h"

#include <stdlib.h>
#include <stdio.h>
#include <git2.h>

#define MAX_COMMAND_LENGTH 2048
#define MAX_PATH_LENGTH 1024
#define MAX_LINK_LENGTH 1024

void DownloadPackage(char Package[], const char PATH[])
{
    git_repository* Repo = NULL;
    git_clone_options Options = GIT_CLONE_OPTIONS_INIT;
    git_libgit2_init();

    char RepoPath[MAX_PATH_LENGTH];
    snprintf(RepoPath, MAX_PATH_LENGTH, "%s/%s", PATH, Package);

    char LinkBuffer[MAX_LINK_LENGTH];
    snprintf(LinkBuffer, MAX_LINK_LENGTH, "%s%s.git", ARCHLINUX_REPOSITORY, Package);

    int Error = git_clone(&Repo, LinkBuffer, RepoPath, &Options);

    if (Error != 0)
    {
        fprintf(
            stderr,
            "Error whilst cloning repo: %d\%d: %s\n",
            Error,
            git_error_last() -> klass,
            git_error_last() -> message
        );

        exit(1);
    }

    git_repository_free(Repo);
    git_libgit2_shutdown();
}

