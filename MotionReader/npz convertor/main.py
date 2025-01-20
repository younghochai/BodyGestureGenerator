import os
import numpy as np

root_file_path = 'C:/Users/pssil/PycharmProjects/pythonProject1/TotalCapture/s1/'

# dummy list
npz_file_name = ['acting1_stageii.npz','acting2_stageii.npz','acting3_stageii.npz',
                 'freestyle1_stageii.npz', 'freestyle2_stageii.npz', 'freestyle3_stageii.npz',
                 'rom1_stageii.npz', 'rom2_stageii.npz', 'rom3_stageii.npz',
                 'walking1_stageii.npz', 'walking2_stageii.npz', 'walking3_stageii.npz']
excluded_files = ['male_stagei.npz', 'female_stagei.npz']

# 수동 경로 지정 방법
temp_name = 'acting1_stageii'

# 추출한 CSV 파일을 저장할 경로
csv_save_path = "C:/Users/pssil/Downloads/TotalCapture/s1/"

# 자동 경로 지정 방법(new!)
file_name_list = os.listdir(root_file_path)

# npz 파일 경로
npz_file_path = root_file_path + temp_name + '.npz'


''' s1 actring1~3 키 값 목록
gender
surface_model_type
mocap_frame_rate
mocap_time_length
markers_latent
latent_labels
markers_latent_vids
trans
poses
betas
num_betas
root_orient
pose_body
pose_hand
pose_jaw
pose_eye
markers
labels
markers_obs
labels_obs
markers_sim
marker_meta
num_markers
'''
text = "root_orient"

# npz 파일 열기
npz_data = np.load(npz_file_path, allow_pickle=True)

for file_name in file_name_list:
    # 제외할 파일명이 리스트에 있는지 확인
    # 딕셔너리 구조가 다를 경우 사용. 목록에 작성한 파일은 제외하고 추출
    if file_name in excluded_files:
        print(f"{file_name} 제외됨.")
        continue

    text1 = '_concat_trans_poses'
    npz_data = np.load(root_file_path+file_name, allow_pickle=True)
    keys = list(npz_data.keys())
    print(keys)
    # for SMPL-X
    a2 = npz_data['trans']
    b2 = npz_data['root_orient']
    c2 = npz_data['pose_body']
    result = np.concatenate((a2,b2,c2),axis=1)

    # for SMPL-H
    # a2 = npz_data['trans']
    # b2 = npz_data['poses'][:,:66]
    # result = np.concatenate((a2,b2),axis=1)
    np.savetxt(csv_save_path + file_name[:-4] + text1 + '.csv', result, delimiter=",")
    print(file_name, " 저장완료.")



# lst = npz_data.files
# for key in lst: # 파일 목록 불러오기(딕셔너리)
#    print(key)
#    print(npz_data[key])
# print(text)
# print(npz_data[text])
# npz_data_len = npz_data[text]
# print(len(npz_data_len[0]))

# gender_data = npz_data['gender']
# gender_data = np.array([gender_data])
# surface_data = npz_data['surface_model_type']
# surface_data = np.array([surface_data])
# frame_data = npz_data['mocap_frame_rate']
# frame_data = npz_data['mocap_framerate'] # for SMPL-H
# frame_data = np.array([frame_data])
# time_data = npz_data['mocap_time_length']
# time_data = np.array([time_data])
# print(gender_data)

# text2 = 'concat_root_body_pose'
# .csv 파일 변환
# np.savetxt(temp_name +'_'+text2+'.csv', result, delimiter=",") #, fmt='%s'
# np.savetxt('acting1_stageii'+'_'+text+'.csv', npz_data[text], delimiter=",") #, fmt='%s'
# np.savetxt('acting1_stageii'+'_'+text+'.csv', npz_data[text], fmt='%s') #, fmt='%s'
# np.savetxt('acting1_stageii_time.csv', time_data, fmt='%s')  # 문자열 포멧으로 변환



'''
### 길이 추출 ###
keys_to_check = ['trans', 'root_orient', 'pose_body']

# npz 파일 열기
npz_data = np.load(npz_file_path, allow_pickle=True)

# 값의 크기를 가져오기
values = [len(npz_data[key][0]) if key in npz_data else 0 for key in keys_to_check]

# 테이블 출력
header = " | ".join(f"{key:^15}" for key in keys_to_check)  # 헤더 가운데 정렬
separator = "-" * len(header)
row = " | ".join(f"{value:^15}" for value in values)  # 값 가운데 정렬

print(header)
print(separator)
print(row)

# NOTE: 결과값 smplx 변환 가이드(20250117) 슬라이드33 참고
'''
