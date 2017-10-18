pipeline {
    agent {
        docker {
            image 'praqma/native-gradle'
            args '-v $HOME/.m2:/home/jenkins/.m2'
            args '-v $HOME/.gradle:/home/jenkins/.gradle'
        }
    }
    stages {
        stage ('Build') {
            steps {
                sh "make clean"
                sh "./gradlew publishToMavenLocal"
            }
        }
        stage ('Publish') {
            steps {
                archiveArtifacts 'out/bin/main'
                archiveArtifacts 'out/bin/results_junit.xml'
                junit 'out/bin/results_junit.xml'
                archiveArtifacts 'build/distributions/*.zip'
            }
        }
    }
}
