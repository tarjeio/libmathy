pipeline {
    agent {
        docker {
            image 'praqma/native-gradle'
            args '-v $HOME/.m2:/home/jenkins/.m2 -v $HOME/.gradle:/home/jenkins/.gradle'
        }
    }
    stages {
        stage ('Increment version'){
            steps {
                sh './gradlew incrementVersion'
            }
        }
        stage ('Build') {
            steps {
                sh "make clean"
                sh "./gradlew publish"
            }
        }
        stage ('Publish') {
            steps {
                archiveArtifacts 'out/lib/libmathy.a'
                archiveArtifacts 'native-app/inc/mathy.h'
                archiveArtifacts 'out/bin/results_junit.xml'
                junit 'out/bin/results_junit.xml'
                archiveArtifacts 'build/distributions/*.zip'
            }
        }
    }
}
