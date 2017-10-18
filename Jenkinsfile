pipeline {
    agent {
        docker { image 'tarjeio/native-make' }
    }
    stages {
        stage ('Get code') {
            steps {
                git "https://github.com/tarjeio/embeddedproject"
            }
        }
        stage ('Build') {
            steps {
                sh "make clean"
                sh "make all"
            }
        }
        stage ('Test') {
            steps {
                sh "make test"
            }
        }
        stage ('Publish') {
            steps {
                archiveArtifacts 'out/bin/main'
                archiveArtifacts 'out/bin/results_junit.xml'
                junit 'out/bin/results_junit.xml'
            }
        }
    }
}
