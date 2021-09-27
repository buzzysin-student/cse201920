# CIA and AAA Security Concepts <!-- omit in toc -->

[prev]: ./index.md
[next]: ./02principles.md
[index]: ./index.md

- [CIA](#cia)
  - [Confidentiality](#confidentiality)
  - [Integrity](#integrity)
  - [Availability](#availability)
- [AAA](#aaa)
  - [Assurance](#assurance)
  - [Authenticity](#authenticity)
  - [Anonymity](#anonymity)

> **Note that these concepts do not have to be applied in terms of software principles only**

## CIA

### Confidentiality

**Confidentiality avoids the unauthorised disclosure of information.**

- Only allow those with authority to access a resource
- Obsure content from parties without authority

Confidentiality tools can include:

- Encryption - obfuscates data for those who do not know how to manage the scrambled information
- Access control - rules/policies that limit access on a "need to know" basis
  - Control gating methods include identity (name or serial number) or role (administrator)
- Authentication - determine the identity or role of a user
  - Combines what a person has, knows and is (e.g. a physical key, a password and a human being)
- Authorisation - determine whether an entity has permission to perform an action on a resource
- Physical security (bank vault, Faraday cage that blocks EM signals)

### Integrity

**Integrity avoids unauthorised alteration of data.**

Integrity tools can include:

- Backups - for archives in case of corruption/for history management
- Checksums - for detecting errors in transmission
- Data correction codes - a specific data storage scheme that allows for error detection

### Availability

**Availability ensures that information is accessible at all times by authorised parties.**

Availability tools can include:

- Distributed Physical Infrastructure
- Computational redundancies - fallbacks and failsafes
- Example of above points: a load balancing servers to ensure a webpage is accessible to users wherever and "whenever" they are

## AAA

### Assurance

### Authenticity

### Anonymity
