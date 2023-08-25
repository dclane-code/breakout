# Breakout

build
```
snapcraft
```

install
```
snap install ./breakout*snap --dangerous
```

connect ppp (for cap setuid ability)
```
snap connect breakout:ppp
```

Do things as root:
```
breakout "cat /etc/shadow"
breakout "/bin/bash"
```

What is interesting is that the confinement still applies, so that even the root shell is restricted

