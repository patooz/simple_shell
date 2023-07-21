#!/bin/bash env bash

set -e

SCRIPTDIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
HOMEDIR="$(git -C "$SCRIPTDIR" rev-parse --show-toplevel)"

set -x

cat > "${HOMEDIR}/AUTHORS" <<- EOF
	 # File contains the Authors of this repo

	$(git -C "$HOMEDIR" log --format='%aN <%aE>' | LC_ALL=UTF-8 sort -uf)
EOF
